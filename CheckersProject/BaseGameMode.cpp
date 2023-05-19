#include "BaseGameMode.h"
#include "Renderer.h"

#include <iostream>
#include <string>
#include <Windows.h>
#include <chrono>
#include <conio.h>
#include <thread>
#include <vector>
#include <iterator>
#include <numeric>

BaseGameMode::BaseGameMode() 
{

}

bool IsVirtualKeyPressed(int VirtKey)
{
	return GetAsyncKeyState(VirtKey) != 0;
}


void BaseGameMode::MainMenu()
{

	while (true)
	{
		InitializeFullBoard();
		RenderBoard();
		//MainMenuRenderer.Draw("Press 0 to start a game of checkers!", { 20, 20 });
	}
	
}

void BaseGameMode::InitializeFullBoard()
{
	for (size_t i = 0; i < 8; i++)
	{
		UniquePtrInitValue = i;
		std::unique_ptr<CheckerBoardQuads> UniquePtrInitValue = std::make_unique<CheckerBoardQuads>(InitNums.at(i));
		UniquePtrInitValue->PopulateQuadWithBaseSymbol();
		QuadStorageVector.emplace_back(*UniquePtrInitValue);
	}
}

void BaseGameMode::RenderBoard()
{
	while (true)
	{

		Renderer BoardRenderer;

		std::vector<CheckerBoardQuads>::iterator QuantIterator = QuadStorageVector.begin();

		//TempVectorForRendering = QuantIterator->Quadrant;
		//BoardRenderer.Draw2DVector(TempVectorForRendering, { 20, 20 });
		//advance(QuantIterator, 1);

		//TempVectorForRendering = QuantIterator->Quadrant;
		//BoardRenderer.Draw2DVector(TempVectorForRendering, { 25, 20 });
		//advance(QuantIterator, 1);





		for (size_t i = 0; i < QuadStorageVector.size(); i++)
		{

			TempVectorForRendering = QuantIterator->Quadrant;
			BoardRenderer.Draw2DVector(TempVectorForRendering, { RenderXCord.at(i), 1 });
			advance(QuantIterator, 1);
		}

		//for (QuantIterator = QuadStorageVector.begin(); QuantIterator < QuadStorageVector.end(); QuantIterator++)
		//{
		//		TempVectorForRendering = QuantIterator->Quadrant;
		//		BoardRenderer.Draw2DVector(TempVectorForRendering, { RenderXCordSetter, 1 });
		//		RenderXCordSetter = RenderXCordSetter + 4;
		//}



		if (IsVirtualKeyPressed(VK_NUMPAD1))
		{
			return;
		}
	}
}

BaseGameMode::~BaseGameMode()
{

}