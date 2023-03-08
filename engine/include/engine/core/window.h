#ifndef __BT_ENGINE_WINDOW_H__
#define __BT_ENGINE_WINDOW_H__

#include <string>
#include <GLFW/glfw3.h>

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
		Window(const std::string_view& title, int32_t width, int32_t height);
		~Window();

		/**
		 * Updates the window.
		 */
		void PollEvents();

		/**
		 * Sets the current OpenGL context to draw to this window.
		 */
		void MakeContextCurrent() const;

		/**
		 * Presents the back buffer to the front.
		 */
		void SwapBuffers() const;

		/**
		 * Clears the back buffer with the specified color
		 * 
		 * @param r The red channel
		 * @param g The green channel
		 * @param b The blue channel
		 */
		void ClearBuffers(float r, float g, float b) const;

	private:
		void SetupCallbacks();

		GLFWwindow* m_pWindow = nullptr;
	};
}

#endif // !__BT_ENGINE_WINDOW_H__
