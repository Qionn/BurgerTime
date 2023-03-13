#include "stdafx.h"

#include "engine/core/window.h"
#include "engine/core/events/keyboard_events.h"
#include "engine/core/events/mouse_events.h"
#include "engine/core/events/window_events.h"

namespace bt::engine
{
	static size_t g_InstanceCount	= 0;

	Window::Window(const std::string_view& title, int32_t width, int32_t height)
	{
		if (g_InstanceCount++ == 0)
		{
			if (!glfwInit())
			{
				throw std::runtime_error("Failed to initialize GLFW!");
			}
		}

		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
		glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);

		m_pWindow = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
		if (m_pWindow == nullptr)
		{
			throw std::runtime_error("Failed to create GLFW window!");
		}

		const GLFWvidmode* pMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		glfwSetWindowPos(m_pWindow, (pMode->width - width) / 2, (pMode->height - height) / 2);

		glfwSetWindowUserPointer(m_pWindow, this);
		SetupCallbacks();

		glfwMakeContextCurrent(m_pWindow);
		if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(&glfwGetProcAddress)))
		{
			throw std::runtime_error("Failed to initialize GLAD!");
		}
		glfwMakeContextCurrent(nullptr);

		glfwShowWindow(m_pWindow);
	}

	Window::~Window()
	{
		SetRecipient(nullptr);

		if (--g_InstanceCount == 0)
		{
			glfwDestroyWindow(m_pWindow);
		}
	}

	void Window::PollEvents()
	{
		glfwPollEvents();
	}

	void Window::MakeContextCurrent() const
	{
		glfwMakeContextCurrent(m_pWindow);
	}

	void Window::SwapBuffers() const
	{
		glfwSwapBuffers(m_pWindow);
	}

	void Window::ClearBuffers(float r, float g, float b) const
	{
		glClearColor(r, g, b, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::SetupCallbacks()
	{
		glfwSetWindowCloseCallback(m_pWindow, [](GLFWwindow* pWindow) {
			auto thisPtr = static_cast<Window*>(glfwGetWindowUserPointer(pWindow));
			EventWindowClose e;
			thisPtr->Message(e);
		});

		glfwSetWindowPosCallback(m_pWindow, [](GLFWwindow* pWindow, int32_t x, int32_t y) {
			auto thisPtr = static_cast<Window*>(glfwGetWindowUserPointer(pWindow));
		EventWindowMove e(x, y);
		thisPtr->Message(e);
		});

		glfwSetWindowSizeCallback(m_pWindow, [](GLFWwindow* pWindow, int32_t width, int32_t height) {
			auto thisPtr = static_cast<Window*>(glfwGetWindowUserPointer(pWindow));
		EventWindowSize e(width, height);
		thisPtr->Message(e);
		});

		glfwSetWindowFocusCallback(m_pWindow, [](GLFWwindow* pWindow, int32_t focused) {
			auto thisPtr = static_cast<Window*>(glfwGetWindowUserPointer(pWindow));
		EventWindowFocus e(focused == GLFW_TRUE);
		thisPtr->Message(e);
		});

		glfwSetKeyCallback(m_pWindow, [](GLFWwindow* pWindow, int32_t key, int32_t scancode, int32_t action, int32_t) {
			auto thisPtr = static_cast<Window*>(glfwGetWindowUserPointer(pWindow));
			switch (action)
			{
				case GLFW_PRESS:
				case GLFW_REPEAT:
				{
					EventKeyboardKeyDown e(key, scancode, action == GLFW_REPEAT);
					thisPtr->Message(e);
					break;
				}

				case GLFW_RELEASE:
				{
					EventKeyboardKeyUp e(key, scancode);
					thisPtr->Message(e);
					break;
				}
			}
		});

		glfwSetCharCallback(m_pWindow, [](GLFWwindow* pWindow, uint32_t codepoint) {
			auto thisPtr = static_cast<Window*>(glfwGetWindowUserPointer(pWindow));
			EventKeyboardChar e(codepoint);
			thisPtr->Message(e);
		});

		glfwSetCursorPosCallback(m_pWindow, [](GLFWwindow* pWindow, double x, double y) {
			auto thisPtr = static_cast<Window*>(glfwGetWindowUserPointer(pWindow));
		EventMouseMove e((float)x, (float)y);
		thisPtr->Message(e);
		});

		glfwSetScrollCallback(m_pWindow, [](GLFWwindow* pWindow, double xDelta, double) {
			auto thisPtr = static_cast<Window*>(glfwGetWindowUserPointer(pWindow));
			double x, y;
			glfwGetCursorPos(pWindow, &x, &y);
			EventMouseScroll e((float)x, (float)y, (float)xDelta);
			thisPtr->Message(e);
		});

		glfwSetMouseButtonCallback(m_pWindow, [](GLFWwindow* pWindow, int32_t button, int32_t action, int32_t) {
			auto thisPtr = static_cast<Window*>(glfwGetWindowUserPointer(pWindow));
			double x, y;
			glfwGetCursorPos(pWindow, &x, &y);

			switch (action)
			{
				case GLFW_PRESS:
				{
					EventMouseButtonDown e((float)x, (float)y, button);
					thisPtr->Message(e);
					break;
				}

				case GLFW_RELEASE:
				{
					EventMouseButtonUp e((float)x, (float)y, button);
					thisPtr->Message(e);
					break;
				}
			}
		});
	}
}
