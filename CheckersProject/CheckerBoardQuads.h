#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Renderer.h"

#include <Windows.h>
#include <chrono>
#include <conio.h>
#include <thread>

class CheckerBoardQuads
{

public:

	//Variables

	int QuadSize = 3;

	int QuadNumber = 0;

	char BaseNumber{ '0' };

	char BaseSymbol{ '~' };

	char Player1Symbol{ 'X' };

	char Player2Symbol{ 'O' };

	std::vector<std::vector<char>> Quadrant{ QuadSize, std::vector<char>(QuadSize) };

	CheckerBoardQuads();

	void AssignQuadNumber(int &QuadInput);

	void PopulateQuadWithBaseSymbol();

	void PopulateQuadWithPlayer1Symbol();

	void PopulateQuadWithPlayer2Symbol();

	void MoveSelectionQuadFill();

	~CheckerBoardQuads();


};

