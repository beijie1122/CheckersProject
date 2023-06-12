#include "CheckerBoardQuads.h"
#include "Renderer.h"

CheckerBoardQuads::CheckerBoardQuads()
{

}

void CheckerBoardQuads::PopulateQuadWithBaseSymbol()
{
	//for (size_t i = 0; i < QuadSize; i++)
	//{
	//	for (size_t j = 0; j < QuadSize; j++)
	//	{
	//		Quadrant[i][j] = BaseSymbol;
	//	}
	//}
	Quadrant[1][1] = '_';
	PopulateQuadWithBorders();
	QuadColor = 1;
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
	PopulateQuadWithBorders();
	QuadColor = 2;

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
	PopulateQuadWithBorders();
	QuadColor = 3;
}

void CheckerBoardQuads::PopulateQuadWithPrepareToBeTaken()
{
	//Quadrant[0][0] = 201;
	//Quadrant[0][2] = 187;
	//Quadrant[2][0] = 200;
	//Quadrant[2][2] = 188;


	for (size_t i = 0; i < QuadSize; i++)
	{
		for (size_t j = 0; j < QuadSize; j++)
		{
			Quadrant[i][j] = PrepareToBeTakenSymbol;
		}
	}
	PopulateQuadWithBorders();
	QuadColor = 4;
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
	PopulateQuadWithBorders();
	QuadColor = 5;
}

void CheckerBoardQuads::PopulateQuadWithBorders()
{
	Quadrant[0][0] = 201;
	//Quadrant[0][0] = 254;
	Quadrant[0][1] = 205;
	Quadrant[0][2] = 187;
	//Quadrant[0][2] = 254;
	Quadrant[1][0] = 186;
	Quadrant[1][2] = 186;
	Quadrant[2][0] = 200;
	//Quadrant[2][0] = 254;
	Quadrant[2][1] = 205;
	Quadrant[2][2] = 188;
	//Quadrant[2][2] = 254;
}

void CheckerBoardQuads::RenderQuad(Renderer &RenderQuad, int XCORD, int YCORD)
{
	RenderQuad.Draw2DVector(Quadrant, { XCORD, YCORD }, QuadColor);
}


CheckerBoardQuads::~CheckerBoardQuads()
{

}
