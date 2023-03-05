#ifndef __BT_ENGINE_TIME_H__
#define __BT_ENGINE_TIME_H__

#include "engine/core/common.h"

namespace bt::engine
{
	// Time ----------------------------------------------------------------------
	// ===========================================================================

	struct Time final
	{
		BT_ENGINE_DISALLOW_IMPLICIT_CONSTRUCTOR(Time)

		static inline float deltaTime = 0.0f;
		static inline constexpr float fixedDeltaTime = 1.0f / 30.0f;

		/**
		 * Returns the time in seconds from when the application started.
		 * 
		 * @returns Time in seconds
		 */
		static float GetTime();
	};
}

#endif // !__BT_ENGINE_TIME_H__
