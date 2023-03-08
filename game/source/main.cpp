#include "core/game.h"

#include <memory>

int main()
{
	auto pGame = std::make_unique<bt::Game>();
	pGame->Start();
	return 0;
}
