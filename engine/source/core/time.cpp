#include "stdafx.h"

#include "engine/core/time.h"

#include <chrono>

namespace bt::engine
{
	using namespace std::chrono;
	static auto g_StartTime = high_resolution_clock::now();

	/* static */ float Time::GetTime()
	{
		return duration<float>(high_resolution_clock::now() - g_StartTime).count();
	}
}
