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

	int QuadColor = 0;

	char BaseNumber{ '0' };

	char BaseSymbol{ '~' };

	char Player1Symbol{ 'X' };

	char Player2Symbol{ 'O' };

	char PrepareToBeTakenSymbol{ '$' };

	char SavedQuadAssignedChar;

	bool IsPlayer1Quad = false;

	bool IsPlayer2Quad = false;

	bool IsUnoccupiedQuad = false;

	bool IsPieceKinged = false;

	std::vector<std::vector<char>> Quadrant{ QuadSize, std::vector<char>(QuadSize) };

	CheckerBoardQuads();

	void AssignQuadNumber(int &QuadInput);

	void PopulateQuadWithBaseSymbol();

	void PopulateQuadWithPlayer1Symbol(char &AssignedNumberFromBaseGame);

	void PopulateQuadWithPlayer2Symbol(char& AssignedNumberFromBaseGame);

	void PopulateQuadWithPrepareToBeTaken();

	void MoveSelectionQuadFill(char& AssignedNumberFromBaseGame);

	void PopulateQuadWithBorders();

	void RenderQuad(Renderer &RenderQuad, int XCORD, int YCORD);

	~CheckerBoardQuads();


};

