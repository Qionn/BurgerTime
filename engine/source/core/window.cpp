#include "stdafx.h"

#include "engine/core/window.h"
#include "engine/events/keyboard_events.h"
#include "engine/events/mouse_events.h"
#include "engine/events/window_events.h"

namespace bt::engine
{
	static size_t g_InstanceCount		= 0;
	static const DWORD g_Style			= WS_OVERLAPPEDWINDOW;
	static const DWORD g_ExStyle		= WS_EX_OVERLAPPEDWINDOW;
	static const TCHAR g_ClassName[]	= TEXT("EngineWindowClass");

	Window::Window(const std::string_view& title, uint32_t width, uint32_t height)
		: m_Width{ width }
		, m_Height{ height }
		, m_hInstance{ GetModuleHandle(nullptr) }
	{
	#ifdef _UNICODE
		m_Title.resize(title.size());
		MultiByteToWideChar(CP_UTF8, 0, title.data(), (int)title.size(), m_Title.data(), (int)m_Title.size());
	#else
		m_Title.assign(title);
	#endif

		SetProcessDPIAware();

		if (g_InstanceCount++ == 0)
		{
			WNDCLASSEX wc = {};

			wc.cbSize			= sizeof(WNDCLASSEX);
			wc.style			= CS_HREDRAW | CS_VREDRAW;
			wc.lpfnWndProc		= &WindowProc;
			wc.cbClsExtra		= sizeof(LONG_PTR);
			wc.hInstance		= m_hInstance;
			wc.lpszClassName	= g_ClassName;

			RegisterClassEx(&wc);
		}

		RECT wr		= {};
		wr.right	= static_cast<LONG>(m_Width);
		wr.bottom	= static_cast<LONG>(m_Height);
		AdjustWindowRectEx(&wr, g_Style, FALSE, g_ExStyle);

		m_Hwnd = CreateWindowEx(
			g_ExStyle, g_ClassName, m_Title.c_str(), g_Style, CW_USEDEFAULT, CW_USEDEFAULT,
			wr.right - wr.left, wr.bottom - wr.top, nullptr, nullptr, m_hInstance, this
		);

		ShowWindow(m_Hwnd, SW_SHOW);
	}

	Window::~Window()
	{
		DestroyWindow(m_Hwnd);

		if (--g_InstanceCount == 0)
		{
			UnregisterClass(g_ClassName, m_hInstance);
		}
	}

	void Window::PollEvents()
	{
		MSG msg;
		while (PeekMessage(&msg, m_Hwnd, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	LRESULT Window::HandleMessage(UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
			case WM_CLOSE:
			{
				EventWindowClose e;
				Message(e);
				return 0;
			}

			case WM_MOVE:
			{
				int32_t x = GET_X_LPARAM(lParam);
				int32_t y = GetSystemMetrics(SM_CYSCREEN) - m_Height - GET_Y_LPARAM(lParam);

				EventWindowMove e(x, y);
				Message(e);

				break;
			}

			case WM_SIZE:
			{
				m_Width = LOWORD(lParam);
				m_Height = HIWORD(lParam);

				EventWindowSize e(m_Width, m_Height);
				Message(e);

				break;
			}

			case WM_SETFOCUS:
			case WM_KILLFOCUS:
			{
				EventWindowFocus e(msg == WM_SETFOCUS);
				Message(e);
				break;
			}

			case WM_KEYDOWN:
			{
				bool repeated = lParam >> 30 & 1;
				auto keycode = static_cast<uint8_t>(wParam);
				auto scancode = static_cast<uint8_t>(lParam >> 16 & 0xff);

				EventKeyboardKeyDown e(keycode, scancode, repeated);
				Message(e);

				break;
			}

			case WM_KEYUP:
			{
				auto keycode = static_cast<uint8_t>(wParam);
				auto scancode = static_cast<uint8_t>(lParam >> 16 & 0xff);

				EventKeyboardKeyUp e(keycode, scancode);
				Message(e);

				break;
			}

			case WM_CHAR:
			{
				bool repeated = lParam >> 30 & 1;
				auto codepoint = static_cast<uint32_t>(wParam);

				EventKeyboardChar e(codepoint, repeated);
				Message(e);

				break;
			}

			case WM_MOUSEMOVE:
			{
				auto x = static_cast<uint32_t>(GET_X_LPARAM(lParam));
				auto y = static_cast<uint32_t>(m_Height - GET_Y_LPARAM(lParam));

				EventMouseMove e(x, y);
				Message(e);

				break;
			}

			case WM_MOUSEWHEEL:
			{
				POINT pos;
				pos.x = GET_X_LPARAM(lParam);
				pos.y = GET_Y_LPARAM(lParam);
				ScreenToClient(m_Hwnd, &pos);

				auto x = static_cast<uint32_t>(pos.x);
				auto y = static_cast<uint32_t>(pos.y);
				float delta = GET_WHEEL_DELTA_WPARAM(wParam) / float(WHEEL_DELTA);

				EventMouseScroll e(x, y, delta);
				Message(e);

				break;
			}

			case WM_LBUTTONDOWN:
			case WM_RBUTTONDOWN:
			case WM_MBUTTONDOWN:
			{
				auto x = static_cast<uint32_t>(GET_X_LPARAM(lParam));
				auto y = static_cast<uint32_t>(m_Height - GET_Y_LPARAM(lParam));
				uint8_t button = 0;

				switch (msg)
				{
					case WM_LBUTTONDOWN:
						button = VK_LBUTTON;
						break;

					case WM_RBUTTONDOWN:
						button = VK_RBUTTON;
						break;

					case WM_MBUTTONDOWN:
						button = VK_MBUTTON;
						break;
				}

				EventMouseButtonDown e(x, y, button);
				Message(e);

				break;
			}

			case WM_LBUTTONUP:
			case WM_RBUTTONUP:
			case WM_MBUTTONUP:
			{
				auto x = static_cast<uint32_t>(GET_X_LPARAM(lParam));
				auto y = static_cast<uint32_t>(m_Height - GET_Y_LPARAM(lParam));
				uint8_t button = 0;

				switch (msg)
				{
					case WM_LBUTTONUP:
						button = VK_LBUTTON;
						break;

					case WM_RBUTTONUP:
						button = VK_RBUTTON;
						break;

					case WM_MBUTTONUP:
						button = VK_MBUTTON;
						break;
				}

				EventMouseButtonUp e(x, y, button);
				Message(e);

				break;
			}
		}

		return DefWindowProc(m_Hwnd, msg, wParam, lParam);
	}

	/* static */ LRESULT CALLBACK Window::WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		static WNDPROC messageImpl = [](HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
			auto pWindow = reinterpret_cast<Window*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
			return pWindow->HandleMessage(msg, wParam, lParam);
		};

		if (msg == WM_CREATE)
		{
			auto pCreateStruct = reinterpret_cast<CREATESTRUCT*>(lParam);
			auto pWindow = reinterpret_cast<Window*>(pCreateStruct->lpCreateParams);
			SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWindow));
			SetWindowLongPtr(hwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(messageImpl));
			return pWindow->HandleMessage(msg, wParam, lParam);
		}

		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}
