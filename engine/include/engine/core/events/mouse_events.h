#ifndef __BT_ENGINE_MOUSE_EVENTS_H__
#define __BT_ENGINE_MOUSE_EVENTS_H__

#include "engine/core/event.h"

namespace bt::engine
{
	// EventMouseMove ------------------------------------------------------------
	// ===========================================================================

	class EventMouseMove final : public Event
	{
	public:
		EventMouseMove(uint32_t x, uint32_t y)
			: Event(BT_ENGINE_THIS_EVENT_ID), x{ x }, y{ y } {}

		uint32_t x, y;
	};

	// EventMouseScroll ----------------------------------------------------------
	// ===========================================================================

	class EventMouseScroll final : public Event
	{
	public:
		EventMouseScroll(uint32_t x, uint32_t y,  float delta)
			: Event(BT_ENGINE_THIS_EVENT_ID), x{ x }, y{ y }, delta { delta } {}

		uint32_t x, y;
		float delta;
	};

	// EventMouseButtonDown ------------------------------------------------------
	// ===========================================================================

	class EventMouseButtonDown final : public Event
	{
	public:
		EventMouseButtonDown(uint32_t x, uint32_t y, uint8_t button)
			: Event(BT_ENGINE_THIS_EVENT_ID), x{ x }, y{ y }, button{ button } {}

		uint32_t x, y;
		uint8_t button;
	};

	// EventMouseButtonUp --------------------------------------------------------
	// ===========================================================================

	class EventMouseButtonUp final : public Event
	{
	public:
		EventMouseButtonUp(uint32_t x, uint32_t y, uint8_t button)
			: Event(BT_ENGINE_THIS_EVENT_ID), x{ x }, y{ y }, button{ button } {}

		uint32_t x, y;
		uint8_t button;
	};
}

#endif // !__BT_ENGINE_MOUSE_EVENTS_H__
