#include "stdafx.h"

#include "engine/scene/component.h"
#include "engine/scene/game_object.h"

namespace bt::engine
{
	Component::Component(GameObject* pOwner)
		: m_pOwner{ pOwner }
	{

	}

	GameObject* Component::GetOwner() const
	{
		return m_pOwner;
	}

	Scene* Component::GetRoot() const
	{
		return m_pOwner->GetRoot();
	}
}
