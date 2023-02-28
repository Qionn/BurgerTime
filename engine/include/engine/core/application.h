#ifndef __BT_ENGINE_APPLICATION_H__
#define __BT_ENGINE_APPLICATION_H__

#include <string>
#include <memory>

#include "engine/core/common.h"
#include "engine/core/window.h"

namespace bt::engine
{
	// Application ---------------------------------------------------------------
	// ===========================================================================

	class Application
	{
		BT_ENGINE_DISALLOW_COPY_AND_MOVE(Application)

	public:
		/**
		 * Creates an application
		 * 
		 * @param name The application name and window title
		 */
		Application(const std::string_view& name);
		virtual ~Application() = default;

		/**
		 * Starts the application.
		 */
		void Start();

		/**
		 * Stops the application.
		 */
		void Stop();

	protected:
		/**
		 * Updates the state of the application once every frame
		 */
		virtual void Update() = 0;

		/**
		 * Updates the state of the application once every fixed interval
		 */
		virtual void FixedUpdate() = 0;

		/**
		 * Renders the application on the screen once every frame.
		 */
		virtual void Render() const = 0;

		/**
		 * Processes an event received by the application.
		 * 
		 * @param e The event that was received
		 */
		virtual void Process(Event& e) = 0;

	private:
		void HandleEvent(Event& e);

		std::string m_Name;
		bool m_IsRunning;

		std::unique_ptr<Window> m_pWindow;
	};
}

#endif // !__BT_ENGINE_APPLICATION_H__
