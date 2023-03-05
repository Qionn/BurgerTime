#include "stdafx.h"

#include "engine/scene/component.h"

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

	bool Component::HasOwner() const
	{
		return (m_pOwner != nullptr);
	}
}
