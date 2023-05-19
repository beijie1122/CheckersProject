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

	std::vector<char> InitNums{'1', '2', '3', '4', '5', '6', '7', '8'};

	std::vector<CheckerBoardQuads> QuadStorageVector ;

	std::vector<std::vector<char>> TempVectorForRendering{ QuadSize, std::vector<char>(QuadSize) };

	std::vector<int> RenderXCord{ 5, 9, 13, 17, 21, 25, 29, 33 };

	std::vector<int> RenderYCord{ 5, 9, 13, 17, 21, 25, 29, 33 };

	BaseGameMode();

	void MainMenu();

	void InitializeFullBoard();

	void RenderBoard();

	~BaseGameMode();


};

