#ifndef __BT_ENGINE_COMPONENT_EVENTS_H__
#define __BT_ENGINE_COMPONENT_EVENTS_H__

#include "engine/core/event.h"
#include "engine/scene/component.h"
#include "engine/utils/family.h"

#include <type_traits>

namespace bt::engine
{
	// EventComponentAttach ------------------------------------------------------
	// ===========================================================================

	class EventComponentAttach final : public Event
	{
	public:
		template<typename T>
		EventComponentAttach(T* pComponent)
			: Event(BT_ENGINE_THIS_EVENT_ID), pComponent{ pComponent }, id{Family<Component>::GetTypeId<T>()}
		{
			static_assert(std::is_base_of_v<Component, T>, "Type T must derive from Component");
		}

		Component* pComponent;
		uint32_t id;
	};

	// EventComponentDetach ------------------------------------------------------
	// ===========================================================================

	class EventComponentDetach final : public Event
	{
	public:
		template<typename T>
		EventComponentDetach(T* pComponent)
			: Event(BT_ENGINE_THIS_EVENT_ID), pComponent{ pComponent }, id{ Family<Component>::GetTypeId<T>() }
		{
			static_assert(std::is_base_of_v<Component, T>, "Type T must derive from Component");
		}

		Component* pComponent;
		uint32_t id;
	};
}

#endif // !__BT_ENGINE_COMPONENT_EVENTS_H__
