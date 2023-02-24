#ifndef __BT_ENGINE_TIME_H__
#define __BT_ENGINE_TIME_H__

#include "engine/core/common.h"

namespace bt::engine
{
	struct Time final
	{
		BT_ENGINE_DISALLOW_IMPLICIT_CONSTRUCTOR(Time)

		static inline float DeltaTime = 0.0f;
		static inline constexpr float FixedDeltaTime = 1.0f / 30.0f;
	};
}

#endif // !__BT_ENGINE_TIME_H__
