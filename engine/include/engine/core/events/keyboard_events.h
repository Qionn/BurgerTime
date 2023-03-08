#ifndef __BT_ENGINE_KEYBOARD_EVENTS_H__
#define __BT_ENGINE_KEYBOARD_EVENTS_H__

#include "engine/core/event.h"

namespace bt::engine
{
	// EventKeyboardKeyDown ------------------------------------------------------
	// ===========================================================================

	class EventKeyboardKeyDown final : public Event
	{
	public:
		inline EventKeyboardKeyDown(int32_t keycode, int32_t scancode, bool repeated)
			: Event(BT_ENGINE_THIS_EVENT_ID), keycode{ keycode }, scancode{ scancode }, repeated{ repeated } {}

		int32_t keycode, scancode;
		bool repeated;
	};

	// EventKeyboardKeyUp --------------------------------------------------------
	// ===========================================================================

	class EventKeyboardKeyUp final : public Event
	{
	public:
		inline EventKeyboardKeyUp(int32_t keycode, int32_t scancode)
			: Event(BT_ENGINE_THIS_EVENT_ID), keycode{ keycode }, scancode{ scancode } {}

		int32_t keycode, scancode;
	};

	// EventKeyboardChar ---------------------------------------------------------
	// ===========================================================================

	class EventKeyboardChar final : public Event
	{
	public:
		explicit inline EventKeyboardChar(uint32_t codepoint)
			: Event(BT_ENGINE_THIS_EVENT_ID), codepoint{ codepoint } {}

		uint32_t codepoint;
	};
}

#endif // !__BT_ENGINE_KEYBOARD_EVENTS_H__
