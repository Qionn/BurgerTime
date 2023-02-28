#include "stdafx.h"

#include "engine/core/application.h"
#include "engine/core/time.h"
#include "engine/events/window_events.h"
#include "engine/utils/timer.h"

namespace bt::engine
{
	Application::Application(const std::string_view& name)
		: m_Name{ name }
		, m_IsRunning{ false }
	{
		m_pWindow = std::make_unique<Window>(name, 640, 360);
		m_pWindow->SetRecipient(std::bind(&Application::HandleEvent, this, std::placeholders::_1));
	}

	void Application::Start()
	{
		m_IsRunning = true;

		Timer timer;
		float lag = 0.0f;

		while (m_IsRunning)
		{
			timer.Reset();
			lag += Time::deltaTime;

			m_pWindow->PollEvents();

			while (lag >= Time::fixedDeltaTime)
			{
				FixedUpdate();
				lag -= Time::fixedDeltaTime;
			}

			Update();
			Render();

			Time::deltaTime = timer.ElapsedSeconds();
		}
	}

	void Application::Stop()
	{
		m_IsRunning = false;
	}

	void Application::HandleEvent(Event& e)
	{
		Process(e);

		e.Handle<EventWindowClose>(
			[this](const auto&) {
				this->Stop();
				return true;
			}
		);
	}
}
