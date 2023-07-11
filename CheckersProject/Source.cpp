#include <iostream>
#include "Renderer.h"
#include "BaseGameMode.h"


int main()
{


	InitializeRenderer();
	std::unique_ptr<BaseGameMode> BaseMode = std::make_unique<BaseGameMode>();
	BaseMode->StartGameMenu();

	return 0;
}