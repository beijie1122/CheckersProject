#include "CheckerBoardQuads.h"

CheckerBoardQuads::CheckerBoardQuads()
{

}

CheckerBoardQuads::CheckerBoardQuads(char QuadNum)
{
	QuadNumber = QuadNum;
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
	Quadrant[1][1] = QuadNumber;
}


CheckerBoardQuads::~CheckerBoardQuads()
{

}
