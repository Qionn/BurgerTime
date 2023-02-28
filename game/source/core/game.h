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
		void Render() const override;
		void Process(Event& e) override;
	};
}

#endif // !__BT_GAME_H__
