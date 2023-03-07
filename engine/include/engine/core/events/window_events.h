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
			: Event(BT_ENGINE_THIS_EVENT_ID) {}
	};

	// EventWindowMove -----------------------------------------------------------
	// ===========================================================================

	class EventWindowMove final : public Event
	{
	public:
		inline EventWindowMove(int32_t x, int32_t y)
			: Event(BT_ENGINE_THIS_EVENT_ID), x{ x } , y{ y } {}

		int32_t x, y;
	};

	// EventWindowSize -----------------------------------------------------------
	// ===========================================================================

	class EventWindowSize final : public Event
	{
	public:
		inline EventWindowSize(uint32_t width, uint32_t height)
			: Event(BT_ENGINE_THIS_EVENT_ID), width{ width }, height{ height } {}

		uint32_t width, height;
	};

	// EventWindowFocus ----------------------------------------------------------
	// ===========================================================================

	class EventWindowFocus final : public Event
	{
	public:
		inline EventWindowFocus(bool focused)
			: Event(BT_ENGINE_THIS_EVENT_ID), focused{ focused } {}

		bool focused;
	};
}

#endif // !__BT_ENGINE_WINDOW_EVENTS_H__
