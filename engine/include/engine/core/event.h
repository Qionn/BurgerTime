#ifndef __BT_ENGINE_EVENT_H__
#define __BT_ENGINE_EVENT_H__

#include <functional>
#include <type_traits>

#include "engine/core/common.h"
#include "engine/utils/family.h"

namespace bt::engine
{
	// Event ---------------------------------------------------------------------
	// ===========================================================================

	class Event
	{
		BT_ENGINE_DISALLOW_COPY_AND_MOVE(Event)

	public:
		/**
		 * Created an empty event with an assigned id.
		 * 
		 * @param id The id of the event
		 */
		Event(uint32_t id);
		virtual ~Event() = default;

		/**
		 * Handles the event by calling the handler when T matches the family typeid of
		 * the event's assigned id
		 * 
		 * @param handler The functor to call
		 */
		template<typename T> void Handle(const std::function<bool(const T&)>& handler)
		{
			if (!m_IsHandled && Family<Event>::IsTypeId<T>(m_Id))
			{
				m_IsHandled = handler(*reinterpret_cast<T*>(this));
			}
		}

	private:
		uint32_t m_Id;
		bool m_IsHandled;
	};
}

#define __EventBaseHelper Event(Family<Event>::GetTypeId<std::remove_reference_t<decltype(*this)>>())

#endif // !__BT_ENGINE_EVENT_H__
