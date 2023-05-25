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

void CheckerBoardQuads::PopulateQuadWithPlayer1Symbol()
{
	for (size_t i = 0; i < QuadSize; i++)
	{
		for (size_t j = 0; j < QuadSize; j++)
		{
			Quadrant[i][j] = Player1Symbol;
		}
	}
	Quadrant[1][1] = BaseNumber;
}

void CheckerBoardQuads::AssignQuadNumber(int& QuadInput)
{
	QuadNumber = QuadInput;
}


CheckerBoardQuads::~CheckerBoardQuads()
{

}
