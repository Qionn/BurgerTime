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
			: __EventBaseHelper, keycode{ keycode }, scancode{ scancode }, repeated{ repeated } {}

		uint8_t keycode, scancode;
		bool repeated;
	};

	// EventKeyboardKeyUp --------------------------------------------------------
	// ===========================================================================

	class EventKeyboardKeyUp final : public Event
	{
	public:
		EventKeyboardKeyUp(uint8_t keycode, uint8_t scancode)
			: __EventBaseHelper, keycode{ keycode }, scancode{ scancode } {}

		uint8_t keycode, scancode;
	};

	// EventKeyboardChar ---------------------------------------------------------
	// ===========================================================================

	class EventKeyboardChar final : public Event
	{
	public:
		EventKeyboardChar(uint32_t codepoint, bool repeated)
			: __EventBaseHelper, codepoint{ codepoint }, repeated{ repeated } {}

		uint32_t codepoint;
		bool repeated;
	};
}

#endif // !__BT_ENGINE_KEYBOARD_EVENTS_H__
