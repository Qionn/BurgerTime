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
		Window(const std::string_view& title, int32_t width, int32_t height);
		~Window();

		void PollEvents();
		void MakeContextCurrent() const;
		void SwapBuffers() const;
		void ClearBuffers(float r, float g, float b) const;

	private:
		void SetupCallbacks();

		GLFWwindow* m_pWindow = nullptr;
	};
}

#endif // !__BT_ENGINE_WINDOW_H__
