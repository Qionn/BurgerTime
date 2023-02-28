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
	};
}

#endif // !__BT_ENGINE_TIME_H__
