#include "stdafx.h"

#include "engine/utils/timer.h"

namespace bt::engine
{
	Timer::Timer()
		: m_StartPoint{ Clock::now() }
	{

	}

	void Timer::Reset()
	{
		m_StartPoint = Clock::now();
	}

	float Timer::ElapsedSeconds() const
	{
		return std::chrono::duration<float>(Clock::now() - m_StartPoint).count();
	}
}
