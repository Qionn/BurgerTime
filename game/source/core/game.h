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
		void Update() override;
		void FixedUpdate() override;
	};
}

BT_ENGINE_APP(Game)

#endif // !__BT_GAME_H__
