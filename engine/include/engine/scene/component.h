#ifndef __BT_ENGINE_COMPONENT_H__
#define __BT_ENGINE_COMPONENT_H__

#include "engine/core/common.h"
#include "engine/core/event.h"
#include "engine/utils/messenger.h"

#include <type_traits>

namespace bt::engine
{
	class GameObject;

	// Component -----------------------------------------------------------------
	// ===========================================================================

	class Component
	{
		BT_ENGINE_DISALLOW_COPY_AND_MOVE(Component)

	public:
		Component(GameObject* pOwner);
		virtual ~Component() = default;

		GameObject* GetOwner() const;

		virtual void Update()			= 0;
		virtual void FixedUpdate()		= 0;
		virtual void Render() const		= 0;
		virtual void Process(Event& e)	= 0;

	private:
		GameObject* m_pOwner = nullptr;
	};
}

#define BT_ENGINE_COMPONENT_ID(type)	bt::engine::Family<bt::engine::Component>::GetTypeId<type>()
#define BT_ENGINE_THIS_COMPONENT_ID		BT_ENGINE_COMPONENT_ID(std::remove_reference_t<decltype(*this)>)

#endif // !__BT_ENGINE_COMPONENT_H__
