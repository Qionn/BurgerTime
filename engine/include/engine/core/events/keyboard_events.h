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
		EventKeyboardKeyDown(uint8_t keycode, uint8_t scancode, bool repeated)
			: Event(BT_ENGINE_THIS_EVENT_ID), keycode{ keycode }, scancode{ scancode }, repeated{ repeated } {}

		uint8_t keycode, scancode;
		bool repeated;
	};

	// EventKeyboardKeyUp --------------------------------------------------------
	// ===========================================================================

	class EventKeyboardKeyUp final : public Event
	{
	public:
		EventKeyboardKeyUp(uint8_t keycode, uint8_t scancode)
			: Event(BT_ENGINE_THIS_EVENT_ID), keycode{ keycode }, scancode{ scancode } {}

		uint8_t keycode, scancode;
	};

	// EventKeyboardChar ---------------------------------------------------------
	// ===========================================================================

	class EventKeyboardChar final : public Event
	{
	public:
		EventKeyboardChar(uint32_t codepoint, bool repeated)
			: Event(BT_ENGINE_THIS_EVENT_ID), codepoint{ codepoint }, repeated{ repeated } {}

		uint32_t codepoint;
		bool repeated;
	};
}

#endif // !__BT_ENGINE_KEYBOARD_EVENTS_H__
