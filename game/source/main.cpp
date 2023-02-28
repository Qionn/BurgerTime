#include "core/game.h"

#include <memory>

int WINAPI wWinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPWSTR, _In_ int)
{
	auto pGame = std::make_unique<bt::Game>();
	pGame->Start();
	return 0;
}
