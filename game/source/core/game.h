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
	};
}

#endif // !__BT_GAME_H__
