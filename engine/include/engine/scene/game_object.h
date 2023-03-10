#ifndef __BT_ENGINE_GAME_OBJECT_H__
#define __BT_ENGINE_GAME_OBJECT_H__

#include "engine/core/common.h"
#include "engine/core/events/game_object_events.h"
#include "engine/scene/components/transform_component.h"
#include "engine/utils/family.h"

#include <memory>
#include <vector>
#include <type_traits>
#include <unordered_map>

namespace bt::engine
{
	class Scene;

	// GameObject ----------------------------------------------------------------
	// ===========================================================================

	class GameObject final
	{
		BT_ENGINE_DISALLOW_COPY_AND_MOVE(GameObject)

	public:
		GameObject(Scene* pRoot);
		~GameObject() = default;

		template<typename T, typename ... Args>
		T* AddComponent(Args&&... args)
		{
			static_assert(std::is_base_of_v<Component, T>, "Type T must derive from Component");
			static_assert(std::is_constructible_v<T, GameObject*, Args...>, "Type T is not constructible with arguments of type GameObject*, Args...");
			const uint32_t id = Family<Component>::template GetTypeId<T>();
			
			if (HasComponent<T>())
			{
				return reinterpret_cast<T*>(m_Components[id].get());
			}

			auto* pComponent = new T(this, std::forward<Args>(args)...);
			m_Components.emplace(id, pComponent);

			EventComponentAttach e(pComponent);
			Process(e);

			return pComponent;
		}

		template<typename T>
		bool RemoveComponent()
		{
			static_assert(std::is_base_of_v<Component, T>, "Type T must derive from Component");
			static_assert(std::negation_v<std::is_same<TransformComponent, T>>, "Removing the TransformComponent is not allowed");

			if (HasComponent<T>())
			{
				const uint32_t id = Family<Component>::template GetTypeId<T>();

				EventComponentDetach e(m_Components[id].get());
				Process(e);

				m_Components.erase(id);
				return true;
			}

			return false;
		}

		template<typename T>
		T* GetComponent() const
		{
			static_assert(std::is_base_of_v<Component, T>, "Type T must derive from Component");
			const uint32_t id = Family<Component>::template GetTypeId<T>();
			auto it = m_Components.find(id);

			if (it == m_Components.end())
			{
				return nullptr;
			}

			return reinterpret_cast<T*>(it->second.get());
		}

		template<typename T>
		bool HasComponent() const
		{
			static_assert(std::is_base_of_v<Component, T>, "Type T must derive from Component");
			const uint32_t id = Family<Component>::template GetTypeId<T>();
			return (m_Components.find(id) != m_Components.end());
		}

		Scene* GetRoot() const;

		void Update();
		void FixedUpdate();
		void Render() const;
		void Process(Event& e);

	private:
		Scene* m_pRoot;
		std::unordered_map<uint32_t, std::unique_ptr<Component>> m_Components;
	};
}

#endif // !__BT_ENGINE_GAME_OBJECT_H__
