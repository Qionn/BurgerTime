#ifndef __BT_ENGINE_SCENE_H__
#define __BT_ENGINE_SCENE_H__

#include "engine/core/common.h"
#include "engine/core/event.h"
#include "engine/scene/game_object.h"

#include <memory>
#include <vector>
#include <queue>

namespace bt::engine
{
	// Scene ---------------------------------------------------------------------
	// ===========================================================================

	class Scene final
	{
		BT_ENGINE_DISALLOW_COPY(Scene)

	public:
		Scene() = default;
		~Scene() = default;

		/**
		 * Creates a new game object and adds it to the scene.
		 *
		 * @return A pointer to the newly created game object.
		 */
		GameObject* AddGameObject();

		/**
		 * Removes a game object from the scene.
		 *
		 * @param pGameObject The game object to remove.
		 * @return True if the game object was successfully removed, false otherwise.
		 */
		bool RemoveGameObject(GameObject* pGameObject);

		/**
		 * Updates all the game objects in the scene.
		 */
		void Update();

		/**
		 * Fixed update method for physics simulation.
		 */
		void FixedUpdate();

		/**
		 * Renders all the game objects in the scene.
		 */
		void Render() const;

		/**
		 * Processes an event received by the application.
		 * 
		 * @param e The event to process
		 */
		void Process(Event& e);

	private:
		std::vector<std::unique_ptr<GameObject>> m_GameObjects;
		std::queue<size_t> m_DeadObjectsIndices;
	};
}

#endif // !__BT_ENGINE_SCENE_H__
