#include "core/game.h"

namespace bt
{
	Game::Game()
		: Application("Burger Time")
	{

	}

	void Game::Load(Scene& scene)
	{
		m_pMesh = std::make_unique<Mesh>(
			std::vector<Vertex>{
				{ {-0.5f, -0.5f, 0.0f} },
				{ {0.5f, -0.5f, 0.0f} },
				{ {0.0f, 0.5f, 0.0f} },
			},
			std::vector<uint16_t>{ 0, 1, 2 }
		);

		m_pMaterial = std::make_unique<Material>("data/shaders/test.vs.glsl", "data/shaders/test.fs.glsl");

		auto go = scene.AddGameObject();
		go->AddComponent<MeshRendererComponent>(m_pMesh.get(), m_pMaterial.get());
	}
}
