#ifndef __BT_ENGINE_WINDOW_H__
#define __BT_ENGINE_WINDOW_H__

#include <string>
#include <windows.h>

#include "engine/core/common.h"
#include "engine/core/event.h"
#include "engine/utils/messenger.h"

namespace bt::engine
{
	// Window --------------------------------------------------------------------
	// ===========================================================================

	class Window final : public Messenger<Event>
	{
		BT_ENGINE_DISALLOW_COPY(Window)

	public:
		/**
		 * Create a new window.
		 * 
		 * @param title Title of the window
		 * @param width Width in pixels
		 * @param height Height in pixels
		 */
		Window(const std::string_view& title, uint32_t width, uint32_t height);
		~Window();

		/**
		 * Updates the window.
		 */
		void PollEvents();

	private:
		LRESULT HandleMessage(UINT msg, WPARAM wParam, LPARAM lParam);
		static LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

		std::basic_string<TCHAR> m_Title;
		uint32_t m_Width, m_Height;

		HWND m_Hwnd;
		HINSTANCE m_hInstance;
	};
}

#endif // !__BT_ENGINE_WINDOW_H__
