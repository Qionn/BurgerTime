#ifndef __BT_ENGINE_APPLICATION_H__
#define __BT_ENGINE_APPLICATION_H__

#include <string>
#include <memory>

#include "engine/core/common.h"
#include "engine/core/window.h"
#include "engine/scene/scene.h"

namespace bt::engine
{
	// Application ---------------------------------------------------------------
	// ===========================================================================

	class Application
	{
		BT_ENGINE_DISALLOW_COPY_AND_MOVE(Application)

	public:
		Application(const std::string_view& name);
		virtual ~Application() = default;

		void Start();
		void Stop();

	protected:
		virtual void Load(Scene& scene) = 0;

	private:
		void HandleEvent(Event& e);

		std::string m_Name;
		bool m_IsRunning;

		std::unique_ptr<Window> m_pWindow;
		std::unique_ptr<Scene> m_pMainScene;
	};
}

#endif // !__BT_ENGINE_APPLICATION_H__
