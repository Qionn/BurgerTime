#include "stdafx.h"

#include "engine/core/application.h"
#include "engine/global/time.h"
#include "engine/utils/timer.h"

namespace bt::engine
{
	Application::Application(const std::string_view& name)
		: m_Name{ name }
		, m_IsRunning{ false }
	{

	}

	void Application::Start()
	{
		m_IsRunning = true;

		Timer timer;
		float lag = 0.0f;

		while (m_IsRunning)
		{
			timer.Reset();
			lag += Time::DeltaTime;

			while (lag >= Time::FixedDeltaTime)
			{
				FixedUpdate();
				lag -= Time::FixedDeltaTime;
			}

			Update();

			Time::DeltaTime = timer.ElapsedSeconds();
		}
	}

	void Application::Stop()
	{
		m_IsRunning = false;
	}

	const std::string& Application::GetName() const
	{
		return m_Name;
	}
}
