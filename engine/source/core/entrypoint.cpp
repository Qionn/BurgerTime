#include "stdafx.h"

#include "engine/core/entrypoint.h"

namespace bt::engine
{
	void Start()
	{
		auto pApp = bt::engine::AppFactory();
		pApp->Start();
	}
}

int main() { bt::engine::Start(); }
int WINAPI wWinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPWSTR, _In_ int) { bt::engine::Start(); }
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) { bt::engine::Start(); }
