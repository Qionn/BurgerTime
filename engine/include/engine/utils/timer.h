#ifndef __BT_ENGINE_TIMER_H__
#define __BT_ENGINE_TIMER_H__

#include <chrono>
#include <type_traits>

#include "engine/core/common.h"

namespace bt::engine
{
	// Timer ---------------------------------------------------------------------
	// ===========================================================================

	class Timer final
	{
	public:
		using Clock = std::chrono::high_resolution_clock;

	public:
		Timer();
		~Timer() = default;

		void Reset();
		float ElapsedSeconds() const;

	private:
		Clock::time_point m_StartPoint;
	};
}

#endif // !__BT_ENGINE_TIMER_H__
