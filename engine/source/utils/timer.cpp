#include "stdafx.h"

#include "engine/core/time.h"
#include "engine/utils/timer.h"

namespace bt::engine
{
	Timer::Timer()
		: m_StartTime{ Time::GetTime() }
	{

	}

	void Timer::Reset()
	{
		m_StartTime = Time::GetTime();
	}

	float Timer::ElapsedSeconds() const
	{
		return (Time::GetTime() - m_StartTime);
	}
}
