#ifndef __BT_GAME_H__
#define __BT_GAME_H__

#include <engine/engine.h>

namespace bt
{
	class Game final : public engine::Application
	{
	public:
		Game();
		~Game() = default;

	private:
		void Load(Scene& scene) override;

		std::unique_ptr<Mesh> m_pMesh;
		std::unique_ptr<Material> m_pMaterial;
	};
}

#endif // !__BT_GAME_H__
