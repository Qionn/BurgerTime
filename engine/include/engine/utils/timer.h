#ifndef __BT_ENGINE_TIMER_H__
#define __BT_ENGINE_TIMER_H__

#include "engine/core/common.h"

namespace bt::engine
{
	// Timer ---------------------------------------------------------------------
	// ===========================================================================

	class Timer final
	{
	public:
		Timer();
		~Timer() = default;

		void Reset();
		float ElapsedSeconds() const;

	private:
		float m_StartTime;
	};
}

#endif // !__BT_ENGINE_TIMER_H__
