#ifndef __BT_ENGINE_WINDOW_EVENTS_H__
#define __BT_ENGINE_WINDOW_EVENTS_H__

#include "engine/core/event.h"

namespace bt::engine
{
	// EventWindowClose ----------------------------------------------------------
	// ===========================================================================

	class EventWindowClose final : public Event
	{
	public:
		inline EventWindowClose()
			: __EventBaseHelper {}
	};

	// EventWindowMove -----------------------------------------------------------
	// ===========================================================================

	class EventWindowMove final : public Event
	{
	public:
		inline EventWindowMove(int32_t x, int32_t y)
			: __EventBaseHelper, x{ x } , y{ y } {}

		int32_t x, y;
	};

	// EventWindowSize -----------------------------------------------------------
	// ===========================================================================

	class EventWindowSize final : public Event
	{
	public:
		inline EventWindowSize(uint32_t width, uint32_t height)
			: __EventBaseHelper, width{ width }, height{ height } {}

		uint32_t width, height;
	};

	// EventWindowFocus ----------------------------------------------------------
	// ===========================================================================

	class EventWindowFocus final : public Event
	{
	public:
		inline EventWindowFocus(bool focused)
			: __EventBaseHelper, focused{ focused } {}

		bool focused;
	};
}

#endif // !__BT_ENGINE_WINDOW_EVENTS_H__
