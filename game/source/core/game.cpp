#include "core/game.h"

#include <fstream>

namespace bt
{
	Game::Game()
		: Application("Burger Time")
	{

	}

	void Game::Load(Scene& scene)
	{
		{
			auto go = scene.AddGameObject();
			go->AddComponent<SpriteComponent>();
			
			auto transform = go->GetComponent<TransformComponent>();
			transform->SetScale({ 100.0f, 100.0f });
			transform->SetPosition({ 320.0f, 180.0f });
		}
	}
}
