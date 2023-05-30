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
	for (int i = 0; i < 64; i++)
	{
		UniquePtrInitValue = i;
		std::unique_ptr<CheckerBoardQuads> UniquePtrInitValue = std::make_unique<CheckerBoardQuads>();
		UniquePtrInitValue->AssignQuadNumber(i);
		if (UniquePtrInitValue->QuadNumber < 8 && UniquePtrInitValue->QuadNumber % 2 != 0)
		{
			UniquePtrInitValue->PopulateQuadWithPlayer2Symbol();
			Player2Pieces.push_back(UniquePtrInitValue->QuadNumber);
		}
		else if (UniquePtrInitValue->QuadNumber > 7 && UniquePtrInitValue->QuadNumber < 15 && UniquePtrInitValue->QuadNumber % 2 == 0)
		{
			UniquePtrInitValue->PopulateQuadWithPlayer2Symbol();
			Player2Pieces.push_back(UniquePtrInitValue->QuadNumber);
		}
		else if (UniquePtrInitValue->QuadNumber > 15 && UniquePtrInitValue->QuadNumber < 24 && UniquePtrInitValue->QuadNumber % 2 != 0)
		{
			UniquePtrInitValue->PopulateQuadWithPlayer2Symbol();
			Player2Pieces.push_back(UniquePtrInitValue->QuadNumber);
		}
		else if (UniquePtrInitValue->QuadNumber > 39 && UniquePtrInitValue->QuadNumber < 48 && UniquePtrInitValue->QuadNumber % 2 == 0)
		{
			UniquePtrInitValue->PopulateQuadWithPlayer1Symbol();
			Player1Pieces.push_back(UniquePtrInitValue->QuadNumber);
		}
		else if (UniquePtrInitValue->QuadNumber > 47 && UniquePtrInitValue->QuadNumber < 56 && UniquePtrInitValue->QuadNumber % 2 != 0)
		{
			UniquePtrInitValue->PopulateQuadWithPlayer1Symbol();
			Player1Pieces.push_back(UniquePtrInitValue->QuadNumber);
		}
		else if (UniquePtrInitValue->QuadNumber > 55 && UniquePtrInitValue->QuadNumber < 64 && UniquePtrInitValue->QuadNumber % 2 == 0)
		{
			UniquePtrInitValue->PopulateQuadWithPlayer1Symbol();
			Player1Pieces.push_back(UniquePtrInitValue->QuadNumber);
		}
		else
		{
			UniquePtrInitValue->PopulateQuadWithBaseSymbol();
		}
		
		QuadStorageVector.emplace_back(*UniquePtrInitValue);
	}
}

void BaseGameMode::RenderBoard()
{
	while (true)
	{

		Renderer BoardRenderer;

		//TempVectorForRendering = QuantIterator->Quadrant;
		//BoardRenderer.Draw2DVector(TempVectorForRendering, { 20, 20 });
		//advance(QuantIterator, 1);

		//TempVectorForRendering = QuantIterator->Quadrant;
		//BoardRenderer.Draw2DVector(TempVectorForRendering, { 25, 20 });
		//advance(QuantIterator, 1);


		int XCordCounter = 0;
		std::vector<CheckerBoardQuads>::iterator QuantIterator = QuadStorageVector.begin();

		for (size_t i = 0; i < QuadStorageVector.size(); i++)
		{
			if (i < 8)
			{
				TempVectorForRendering = QuantIterator->Quadrant;
				BoardRenderer.Draw2DVector(TempVectorForRendering, { RenderXCord.at(XCordCounter), RenderYCord.at(0) });
				advance(QuantIterator, 1);
				XCordCounter++;
			}

			else if (i >= 8 && i < 16)
			{
				if (XCordCounter > 7)
				{
					XCordCounter = 0;
				}
				TempVectorForRendering = QuantIterator->Quadrant;
				BoardRenderer.Draw2DVector(TempVectorForRendering, { RenderXCord.at(XCordCounter), RenderYCord.at(1) });
				advance(QuantIterator, 1);
				XCordCounter++;
			}
			else if (i >= 16 && i < 24)
			{
				if (XCordCounter > 7)
				{
					XCordCounter = 0;
				}
				TempVectorForRendering = QuantIterator->Quadrant;
				BoardRenderer.Draw2DVector(TempVectorForRendering, { RenderXCord.at(XCordCounter), RenderYCord.at(2) });
				advance(QuantIterator, 1);
				XCordCounter++;
			}
			else if (i >= 24 && i < 32)
			{
				if (XCordCounter > 7)
				{
					XCordCounter = 0;
				}
				TempVectorForRendering = QuantIterator->Quadrant;
				BoardRenderer.Draw2DVector(TempVectorForRendering, { RenderXCord.at(XCordCounter), RenderYCord.at(3) });
				advance(QuantIterator, 1);
				XCordCounter++;
			}
			else if (i >= 32 && i < 40)
			{
				if (XCordCounter > 7)
				{
					XCordCounter = 0;
				}
				TempVectorForRendering = QuantIterator->Quadrant;
				BoardRenderer.Draw2DVector(TempVectorForRendering, { RenderXCord.at(XCordCounter), RenderYCord.at(4) });
				advance(QuantIterator, 1);
				XCordCounter++;
			}
			else if (i >= 40 && i < 48)
			{
				if (XCordCounter > 7)
				{
					XCordCounter = 0;
				}
				TempVectorForRendering = QuantIterator->Quadrant;
				BoardRenderer.Draw2DVector(TempVectorForRendering, { RenderXCord.at(XCordCounter), RenderYCord.at(5) });
				advance(QuantIterator, 1);
				XCordCounter++;
			}
			else if (i >= 48 && i < 56)
			{
				if (XCordCounter > 7)
				{
					XCordCounter = 0;
				}
				TempVectorForRendering = QuantIterator->Quadrant;
				BoardRenderer.Draw2DVector(TempVectorForRendering, { RenderXCord.at(XCordCounter), RenderYCord.at(6) });
				advance(QuantIterator, 1);
				XCordCounter++;
			}
			else if (i >= 56 && i < 64)
			{
				if (XCordCounter > 7)
				{
					XCordCounter = 0;
				}
				TempVectorForRendering = QuantIterator->Quadrant;
				BoardRenderer.Draw2DVector(TempVectorForRendering, { RenderXCord.at(XCordCounter), RenderYCord.at(7) });
				advance(QuantIterator, 1);
				XCordCounter++;
			}

			BoardRenderer.DrawVectorInt(Player2Pieces, { 1, 1 });
			BoardRenderer.DrawVectorInt(Player1Pieces, { 1, 2 });

			//else if (i > 8 && i < 17)
			//{
			//	for (size_t j = 0; j < 9; j++)
			//	{
			//		BoardRenderer.Draw2DVector(TempVectorForRendering, { RenderXCord.at(j), RenderYCord.at(1) });
			//		advance(QuantIterator, 1);
			//	}
			//}
		}
		
		//for (QuantIterator = QuadStorageVector.begin(); QuantIterator < QuadStorageVector.end(); QuantIterator++)
		//{
		//		TempVectorForRendering = QuantIterator->Quadrant;
		//		BoardRenderer.Draw2DVector(TempVectorForRendering, { RenderXCordSetter, 1 });
		//		RenderXCordSetter = RenderXCordSetter + 4;
		//}

		if (IsQuadSelectedToMove == false)
		{
			BoardRenderer.Draw("Select A Quad", { 1, 4 });
			if (IsVirtualKeyPressed(VK_NUMPAD2))
			{
				SelectedQuadValue = Player1Pieces.at(1);
				SelectedQuadMove1Value = SelectedQuadValue - 9;
				SelectedQuadMove2Value = SelectedQuadValue - 7;
				std::vector<CheckerBoardQuads>::iterator MoveIterator = QuadStorageVector.begin();

				for (size_t i = 0; i < QuadStorageVector.size(); i++)
				{
					if (i == Player1Pieces.at(1))
					{
						MoveIterator->MoveSelectionQuadFill();
						std::vector<CheckerBoardQuads>::iterator MoveIterator1 = QuadStorageVector.begin();
						for (size_t i = 0; i < QuadStorageVector.size(); i++)
						{
							if (i == SelectedQuadMove1Value)
							{
								MoveIterator1->MoveSelectionQuadFill();
								advance(MoveIterator1, 1);
							}
							else if (i == SelectedQuadMove2Value)
							{
								MoveIterator1->MoveSelectionQuadFill();
								advance(MoveIterator1, 1);
							}
							else
							{
								advance(MoveIterator1, 1);
							}
						}
					}
					else
					{
						advance(MoveIterator, 1);
					}
				}
				IsQuadSelectedToMove = true;
			}
		}
		else if (IsQuadSelectedToMove == true);
		{
			BoardRenderer.Draw("Select an area to move to", { 1, 4 });
			if (IsVirtualKeyPressed(VK_NUMPAD1))
			{
				std::vector<CheckerBoardQuads>::iterator MoveIterator2 = QuadStorageVector.begin();
				for (size_t i = 0; i < QuadStorageVector.size(); i++)
				{
					BoardRenderer.Draw("Pressed 1", { 1, 3 });
					if (i == SelectedQuadMove1Value)
					{
						MoveIterator2->PopulateQuadWithPlayer1Symbol();
						advance(MoveIterator2, 1);
					}
					else if (i == SelectedQuadMove2Value)
					{
						MoveIterator2->PopulateQuadWithBaseSymbol();
						advance(MoveIterator2, 1);
					}
					else if (i == Player1Pieces.at(1))
					{
						MoveIterator2->PopulateQuadWithBaseSymbol();
						advance(MoveIterator2, 1);
					}
					else
					{
						advance(MoveIterator2, 1);
					}
				}
				Player1Pieces.at(1) = SelectedQuadMove1Value;
			}
			else if (IsVirtualKeyPressed(VK_NUMPAD3))
			{
				std::vector<CheckerBoardQuads>::iterator MoveIterator2 = QuadStorageVector.begin();
				for (size_t i = 0; i < QuadStorageVector.size(); i++)
				{
					BoardRenderer.Draw("Pressed 2", { 1, 3 });
					if (i == SelectedQuadMove1Value)
					{
						MoveIterator2->PopulateQuadWithBaseSymbol();
						advance(MoveIterator2, 1);
					}
					else if (i == SelectedQuadMove2Value)
					{
						MoveIterator2->PopulateQuadWithPlayer1Symbol();
						advance(MoveIterator2, 1);
					}
					else if (i == Player1Pieces.at(1))
					{
						MoveIterator2->PopulateQuadWithBaseSymbol();
						advance(MoveIterator2, 1);
					}
					else
					{
						advance(MoveIterator2, 1);
					}
				}
				Player1Pieces.at(1) = SelectedQuadMove2Value;
			}
			IsQuadSelectedToMove = false;
		}

		
	}
}

BaseGameMode::~BaseGameMode()
{

}