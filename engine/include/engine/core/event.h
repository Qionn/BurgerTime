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
		Event(uint32_t id);
		virtual ~Event() = default;

		template<typename T> void Handle(const std::function<bool(const T&)>& handler)
		{
			if (!m_IsHandled && Family<Event>::IsTypeId<T>(m_Id))
			{
				m_IsHandled = handler(*reinterpret_cast<T*>(this));
			}
		}

		bool IsHandled() const;

	private:
		uint32_t m_Id;
		bool m_IsHandled;
	};
}

#define BT_ENGINE_EVENT_ID(type)	bt::engine::Family<bt::engine::Event>::GetTypeId<type>()
#define BT_ENGINE_THIS_EVENT_ID		BT_ENGINE_EVENT_ID(std::remove_reference_t<decltype(*this)>)

#endif // !__BT_ENGINE_EVENT_H__
