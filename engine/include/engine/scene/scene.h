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

		GameObject* AddGameObject();
		bool RemoveGameObject(GameObject* pGameObject);

		void Update();
		void FixedUpdate();
		void Render() const;
		void Process(Event& e);

	private:
		std::vector<std::unique_ptr<GameObject>> m_GameObjects;
		std::queue<size_t> m_DeadObjectsIndices;
	};
}

#endif // !__BT_ENGINE_SCENE_H__
