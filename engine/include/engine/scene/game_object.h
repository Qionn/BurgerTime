#ifndef __BT_ENGINE_GAME_OBJECT_H__
#define __BT_ENGINE_GAME_OBJECT_H__

#include "engine/core/common.h"
#include "engine/core/events/component_events.h"
#include "engine/scene/component.h"
#include "engine/scene/components/transform_component.h"
#include "engine/utils/family.h"

#include <memory>
#include <type_traits>
#include <unordered_map>

namespace bt::engine
{
	class Component;

	// GameObject ----------------------------------------------------------------
	// ===========================================================================

	class GameObject final
	{
		BT_ENGINE_DISALLOW_COPY_AND_MOVE(GameObject)

	public:
		GameObject();
		~GameObject() = default;

		/**
		 * Adds a component of type T to the game object.
		 *
		 * @tparam T The type of component to add.
		 * @tparam Args The types of arguments to pass to the component's constructor.
		 * @param args The arguments to pass to the component's constructor.
		 * @returns A weak pointer to the added component of type T.
		 */
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

		/**
		 * Removes the component of type T from the game object.
		 *
		 * @tparam T The type of component to remove.
		 * @returns True if the component was removed, false otherwise.
		 */
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

		/**
		 * Returns true if the game object has a component of type T, false otherwise.
		 *
		 * @tparam T The type of component to check for.
		 * @returns True if the game object has a component of type T, false otherwise.
		 */
		template<typename T>
		bool HasComponent() const
		{
			static_assert(std::is_base_of_v<Component, T>, "Type T must derive from Component");
			const uint32_t id = Family<Component>::template GetTypeId<T>();
			return (m_Components.find(id) != m_Components.end());
		}

		/**
		 * Updates all the components of the game object.
		 */
		void Update();

		/**
		 * Fixed update method for physics simulation.
		 */
		void FixedUpdate();

		/**
		 * Renders all the components of the game object.
		 */
		void Render() const;

		/**
		 * Processes an event received by the scene.
		 *
		 * @param e The event to process
		 */
		void Process(Event& e);

	private:
		std::unordered_map<uint32_t, std::unique_ptr<Component>> m_Components;
	};
}

#endif // !__BT_ENGINE_GAME_OBJECT_H__
