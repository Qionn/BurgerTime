#include "stdafx.h"

#include "engine/scene/scene.h"

namespace bt::engine
{
	GameObject* Scene::AddGameObject()
	{
		auto& objectIt = m_GameObjects.emplace_back(std::make_unique<GameObject>());
		return objectIt.get();
	}

	bool Scene::RemoveGameObject(GameObject* pGameObject)
	{
		auto objectIt = std::find_if(
			m_GameObjects.begin(), m_GameObjects.end(),
			[&](const auto& pObject) {
				return pObject.get() == pGameObject;
			}
		);

		if (objectIt != m_GameObjects.end())
		{
			m_DeadObjectsIndices.push(std::distance(m_GameObjects.begin(), objectIt));
			return true;
		}

		return false;
	}

	void Scene::Update()
	{
		while (!m_DeadObjectsIndices.empty())
		{
			m_GameObjects.erase(m_GameObjects.begin() + m_DeadObjectsIndices.front());
			m_DeadObjectsIndices.pop();
		}

		for (auto& pObject : m_GameObjects)
		{
			pObject->Update();
		}
	}

	void Scene::FixedUpdate()
	{
		for (auto& pObject : m_GameObjects)
		{
			pObject->FixedUpdate();
		}
	}

	void Scene::Render() const
	{
		for (auto& pObject : m_GameObjects)
		{
			pObject->Render();
		}
	}

	void Scene::Process(Event& e)
	{
		for (auto& pObject : m_GameObjects)
		{
			pObject->Process(e);

			if (e.IsHandled())
			{
				break;
			}
		}
	}
}
