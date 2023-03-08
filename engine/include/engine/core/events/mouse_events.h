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
		inline EventMouseMove(float x, float y)
			: Event(BT_ENGINE_THIS_EVENT_ID), x{ x }, y{ y } {}

		float x, y;
	};

	// EventMouseScroll ----------------------------------------------------------
	// ===========================================================================

	class EventMouseScroll final : public Event
	{
	public:
		inline EventMouseScroll(float x, float y, float delta)
			: Event(BT_ENGINE_THIS_EVENT_ID), x{ x }, y{ y }, delta { delta } {}

		float x, y;
		float delta;
	};

	// EventMouseButtonDown ------------------------------------------------------
	// ===========================================================================

	class EventMouseButtonDown final : public Event
	{
	public:
		inline EventMouseButtonDown(float x, float y, int32_t button)
			: Event(BT_ENGINE_THIS_EVENT_ID), x{ x }, y{ y }, button{ button } {}

		float x, y;
		int32_t button;
	};

	// EventMouseButtonUp --------------------------------------------------------
	// ===========================================================================

	class EventMouseButtonUp final : public Event
	{
	public:
		inline EventMouseButtonUp(float x, float y, int32_t button)
			: Event(BT_ENGINE_THIS_EVENT_ID), x{ x }, y{ y }, button{ button } {}

		float x, y;
		int32_t button;
	};
}

#endif // !__BT_ENGINE_MOUSE_EVENTS_H__
