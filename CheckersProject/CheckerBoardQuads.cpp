#include "CheckerBoardQuads.h"

CheckerBoardQuads::CheckerBoardQuads()
{

}

void CheckerBoardQuads::PopulateQuadWithBaseSymbol()
{
	for (size_t i = 0; i < QuadSize; i++)
	{
		for (size_t j = 0; j < QuadSize; j++)
		{
			Quadrant[i][j] = BaseSymbol;
		}
	}
	Quadrant[1][1] = BaseNumber;
}

void CheckerBoardQuads::PopulateQuadWithPlayer1Symbol(char& AssignedNumberFromBaseGame)
{
	for (size_t i = 0; i < QuadSize; i++)
	{
		for (size_t j = 0; j < QuadSize; j++)
		{
			Quadrant[i][j] = Player1Symbol;
		}
	}
	Quadrant[1][1] = AssignedNumberFromBaseGame;
}

void CheckerBoardQuads::PopulateQuadWithPlayer2Symbol(char& AssignedNumberFromBaseGame)
{
	for (size_t i = 0; i < QuadSize; i++)
	{
		for (size_t j = 0; j < QuadSize; j++)
		{
			Quadrant[i][j] = Player2Symbol;
		}
	}
	Quadrant[1][1] = AssignedNumberFromBaseGame;
}

void CheckerBoardQuads::AssignQuadNumber(int& QuadInput)
{
	QuadNumber = QuadInput;
}

void CheckerBoardQuads::MoveSelectionQuadFill(char& AssignedNumberFromBaseGame)
{
	for (size_t i = 0; i < QuadSize; i++)
	{
		for (size_t j = 0; j < QuadSize; j++)
		{
			Quadrant[i][j] = '*';
		}
	}
	Quadrant[1][1] = AssignedNumberFromBaseGame;
}


CheckerBoardQuads::~CheckerBoardQuads()
{

}
