#include "stdafx.h"

#include "engine/scene/component.h"
#include "engine/scene/game_object.h"

namespace bt::engine
{
	GameObject::GameObject(Scene* pRoot)
		: m_pRoot{ pRoot }
	{
		AddComponent<TransformComponent>();
	}

	Scene* GameObject::GetRoot() const
	{
		return m_pRoot;
	}

	void GameObject::Update()
	{
		for (auto& [id, pComponent] : m_Components)
		{
			pComponent->Update();
		}
	}

	void GameObject::FixedUpdate()
	{
		for (auto& [id, pComponent] : m_Components)
		{
			pComponent->FixedUpdate();
		}
	}

	void GameObject::Render() const
	{
		for (const auto& [id, pComponent] : m_Components)
		{
			pComponent->Render();
		}
	}

	void GameObject::Process(Event& e)
	{
		for (auto& [id, pComponent] : m_Components)
		{
			pComponent->Process(e);

			if (e.IsHandled())
			{
				break;
			}
		}
	}
}
