#ifndef __BT_ENGINE_COMPONENT_EVENTS_H__
#define __BT_ENGINE_COMPONENT_EVENTS_H__

#include "engine/core/event.h"

#include <memory>

namespace bt::engine
{
	class Component;

	// EventComponentAttach ------------------------------------------------------
	// ===========================================================================

	class EventComponentAttach final : public Event
	{
	public:
		EventComponentAttach(Component* pComponent)
			: __EventBaseHelper, pComponent{ pComponent } {}

		Component* pComponent;
	};

	// EventComponentDetach ------------------------------------------------------
	// ===========================================================================

	class EventComponentDetach final : public Event
	{
	public:
		EventComponentDetach(Component* pComponent)
			: __EventBaseHelper, pComponent{ pComponent } {}

		Component* pComponent;
	};
}

#endif // !__BT_ENGINE_COMPONENT_EVENTS_H__
