#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include "CheckerBoardQuads.h"
class BaseGameMode
{
public: 

	int UniquePtrInitValue = 0;

	int QuadSize = 3;

	int RenderXCordSetter = 5;

	std::vector<char> InitNums{'1', '2', '3', '4', '5', '6', '7', '8', '9'};

	std::vector<CheckerBoardQuads> QuadStorageVector ;

	std::vector<std::vector<char>> TempVectorForRendering{ QuadSize, std::vector<char>(QuadSize) };

	std::vector<int> RenderXCord{ 5, 9, 13, 17, 21, 25, 29, 33, 37, 41 };

	std::vector<int> RenderYCord{ 5, 8, 11, 14, 17, 20, 23, 26, 29, 32 };

	std::vector<int> Player1Pieces{};
	
	std::vector<int> Player2Pieces{};

	int MoveSelectionValue1 = 9;

	int MoveSelectionValue2 = 7;

	int SelectedQuadValue;

	int SelectedQuadMove1Value;

	int SelectedQuadMove2Value;

	int RenderYCordAdjust{ 0 };

	bool IsQuadSelectedToMove = false;

	BaseGameMode();

	void MainMenu();

	void InitializeFullBoard();

	void RenderBoard();

	~BaseGameMode();


};

