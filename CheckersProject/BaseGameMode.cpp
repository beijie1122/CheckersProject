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
			UniquePtrInitValue->PopulateQuadWithPlayer2Symbol(Player2QuadSelectionChars.at(Player2QuadSelectionCharsVariable));
			Player2QuadSelectionCharsVariable++;
			Player2Pieces.push_back(UniquePtrInitValue->QuadNumber);
		}
		else if (UniquePtrInitValue->QuadNumber > 7 && UniquePtrInitValue->QuadNumber < 15 && UniquePtrInitValue->QuadNumber % 2 == 0)
		{
			UniquePtrInitValue->PopulateQuadWithPlayer2Symbol(Player2QuadSelectionChars.at(Player2QuadSelectionCharsVariable));
			Player2QuadSelectionCharsVariable++;
			Player2Pieces.push_back(UniquePtrInitValue->QuadNumber);
		}
		else if (UniquePtrInitValue->QuadNumber > 15 && UniquePtrInitValue->QuadNumber < 24 && UniquePtrInitValue->QuadNumber % 2 != 0)
		{
			UniquePtrInitValue->PopulateQuadWithPlayer2Symbol(Player2QuadSelectionChars.at(Player2QuadSelectionCharsVariable));
			Player2QuadSelectionCharsVariable++;
			Player2Pieces.push_back(UniquePtrInitValue->QuadNumber);
		}
		else if (UniquePtrInitValue->QuadNumber > 39 && UniquePtrInitValue->QuadNumber < 48 && UniquePtrInitValue->QuadNumber % 2 == 0)
		{
			UniquePtrInitValue->PopulateQuadWithPlayer1Symbol(Player1QuadSelectionChars.at(Player1QuadSelectionCharsVariable));
			Player1QuadSelectionCharsVariable++;
			Player1Pieces.push_back(UniquePtrInitValue->QuadNumber);
		}
		else if (UniquePtrInitValue->QuadNumber > 47 && UniquePtrInitValue->QuadNumber < 56 && UniquePtrInitValue->QuadNumber % 2 != 0)
		{
			UniquePtrInitValue->PopulateQuadWithPlayer1Symbol(Player1QuadSelectionChars.at(Player1QuadSelectionCharsVariable));
			Player1QuadSelectionCharsVariable++;
			Player1Pieces.push_back(UniquePtrInitValue->QuadNumber);
		}
		else if (UniquePtrInitValue->QuadNumber > 55 && UniquePtrInitValue->QuadNumber < 64 && UniquePtrInitValue->QuadNumber % 2 == 0)
		{
			UniquePtrInitValue->PopulateQuadWithPlayer1Symbol(Player1QuadSelectionChars.at(Player1QuadSelectionCharsVariable));
			Player1QuadSelectionCharsVariable++;
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

			if (IsPlayer1Turn == true)
			{
				BoardRenderer.Draw("Player 1's Turn!", { 50, 1 });
			}
			else if (IsPlayer2Turn == true)
			{
				BoardRenderer.Draw("Player 2's Turn!", { 50, 1 });
			}

			BoardRenderer.DrawInt(LeftHandBoundryValue, { 40, 1 });

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
		}
		else if (IsQuadSelectedToMove == true)
		{
			BoardRenderer.Draw("TEST", { 1, 4 });
		}


			if (IsVirtualKeyPressed(VK_NUMPAD1))
			{
				CheckPlayerTurnWithQuadSetup(0, Player2QuadSelectionChars.size() - 1);
			}
			else if (IsVirtualKeyPressed(VK_NUMPAD2))
			{
				CheckPlayerTurnWithQuadSetup(1, Player2QuadSelectionChars.size() - 2);
			}
			else if (IsVirtualKeyPressed(VK_NUMPAD3))
			{
				CheckPlayerTurnWithQuadSetup(2, Player2QuadSelectionChars.size() - 3);
			}
			else if (IsVirtualKeyPressed(VK_NUMPAD4))
			{
				CheckPlayerTurnWithQuadSetup(3, Player2QuadSelectionChars.size() - 4);
			}
			else if (IsVirtualKeyPressed(VK_NUMPAD5))
			{
				CheckPlayerTurnWithQuadSetup(4, Player2QuadSelectionChars.size() - 5);
			}
			else if (IsVirtualKeyPressed(VK_NUMPAD6))
			{
				CheckPlayerTurnWithQuadSetup(5, Player2QuadSelectionChars.size() - 6);
			}
			else if (IsVirtualKeyPressed(VK_NUMPAD7))
			{
				CheckPlayerTurnWithQuadSetup(6, Player2QuadSelectionChars.size() - 7);
			}
			else if (IsVirtualKeyPressed(VK_NUMPAD8))
			{
				CheckPlayerTurnWithQuadSetup(7, Player2QuadSelectionChars.size() - 8);
			}
			else if (IsVirtualKeyPressed(VK_NUMPAD9))
			{
				CheckPlayerTurnWithQuadSetup(8, Player2QuadSelectionChars.size() - 9);
			}
			else if (IsVirtualKeyPressed(VK_NUMPAD0))
			{
				CheckPlayerTurnWithQuadSetup(9, Player2QuadSelectionChars.size() - 10);
			}
			else if (IsVirtualKeyPressed(0x4F)) //O Key
			{
				CheckPlayerTurnWithQuadSetup(10, Player2QuadSelectionChars.size() - 11);
			}
			else if (IsVirtualKeyPressed(0x50)) //P Key
			{
				CheckPlayerTurnWithQuadSetup(11, Player2QuadSelectionChars.size() - 12);
			}
	
			if (IsVirtualKeyPressed(0x41)) // A Key
			{
				if (IsPlayer1Turn == true)
				{
					MoveSelectedQuadToLeftHandQuad(Player1Pieces);
				}
				else if (IsPlayer2Turn == true)
				{
					MoveSelectedQuadToLeftHandQuad(Player2Pieces);
				}
				
			}
			else if (IsVirtualKeyPressed(0x44)) //D key
			{
				if (IsPlayer1Turn == true)
				{
					MoveSelectedQuadToRightHandQuad(Player1Pieces);
				}
				else if (IsPlayer2Turn == true)
				{
					MoveSelectedQuadToRightHandQuad(Player2Pieces);
				}
			}
			else if (IsVirtualKeyPressed(0x45)) //E key
			{
				if (IsPlayer1Turn == true)
				{
					CancelMovement(Player1Pieces);
				}
				else if (IsPlayer2Turn == true)
				{
					CancelMovement(Player2Pieces);
				}
			}
	}
}

void BaseGameMode::Player1MovePieceSetup(int SelectedQuad)
{
	SelectedQuadValue = Player1Pieces.at(SelectedQuad);
	SelectedQuadMove1Value = SelectedQuadValue - 9;
	CheckIfLeftHandQuadMoveValueIsOccupied(SelectedQuad, Player1Pieces, Player2Pieces); 
	SelectedQuadMove2Value = SelectedQuadValue - 7;
	CheckIfRightHandQuadMoveValueIsOccupied(SelectedQuad, Player1Pieces, Player2Pieces);

	std::vector<CheckerBoardQuads>::iterator MoveIterator = QuadStorageVector.begin();

	for (size_t i = 0; i < QuadStorageVector.size(); i++)
	{
		if (i == Player1Pieces.at(SelectedQuad))
		{
			MoveIterator->MoveSelectionQuadFill(SelectedQuadMoveBaseQuadCharValue);
			std::vector<CheckerBoardQuads>::iterator MoveIterator1 = QuadStorageVector.begin();

			for (size_t i = 0; i < QuadStorageVector.size(); i++)
			{
				if (i == SelectedQuadMove1Value)
				{
					CheckIfPieceIsOnLeftEdgeOfBoard();
					CheckIffPieceIsOnRightEdgeOfBoard();
					if (SelectedQuadMove1Value >= LeftHandBoundryValue && IsPieceAtLeftEdgeOfBoard == false)
					{
						MoveIterator1->MoveSelectionQuadFill(SelectedQuadMove1CharValue);
						advance(MoveIterator1, 1);
					}
					else
					{
						advance(MoveIterator1, 1);
					}

				}
				else if (i == SelectedQuadMove2Value && IsPieceAtRightEdgeOfBoard == false) 
				{
					if (SelectedQuadMove2Value <= RightHandBoundryValue)
					{
						MoveIterator1->MoveSelectionQuadFill(SelectedQuadMove2CharValue);
						advance(MoveIterator1, 1);
					}
					else
					{
						advance(MoveIterator1, 1);
					}
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

void BaseGameMode::Player2MovePieceSetup(int SelectedQuad)
{
	SelectedQuadValue = Player2Pieces.at(SelectedQuad);
	SelectedQuadMove1Value = SelectedQuadValue + 7;
	CheckIfLeftHandQuadMoveValueIsOccupied(SelectedQuad, Player2Pieces, Player1Pieces);
	SelectedQuadMove2Value = SelectedQuadValue + 9;
	CheckIfRightHandQuadMoveValueIsOccupied(SelectedQuad, Player2Pieces, Player1Pieces);
	std::vector<CheckerBoardQuads>::iterator MoveIterator = QuadStorageVector.begin();

	for (size_t i = 0; i < QuadStorageVector.size(); i++)
	{
		if (i == Player2Pieces.at(SelectedQuad))
		{
			MoveIterator->MoveSelectionQuadFill(SelectedQuadMoveBaseQuadCharValue);
			std::vector<CheckerBoardQuads>::iterator MoveIterator1 = QuadStorageVector.begin();
			for (size_t i = 0; i < QuadStorageVector.size(); i++)
			{
				CheckDownwardValueforQuadMovement(SelectedQuad, Player2Pieces);
				if (i == SelectedQuadMove1Value)
				{
					CheckIfPieceIsOnLeftEdgeOfBoard();
					CheckIffPieceIsOnRightEdgeOfBoard();
					if (SelectedQuadMove1Value >= LeftHandBoundryValue)
					{
						MoveIterator1->MoveSelectionQuadFill(SelectedQuadMove1CharValue);
						advance(MoveIterator1, 1);
					}
					else
					{
						advance(MoveIterator1, 1);
					}
				}
				else if (i == SelectedQuadMove2Value)
				{
					if (SelectedQuadMove2Value <= RightHandBoundryValue)
					{
						MoveIterator1->MoveSelectionQuadFill(SelectedQuadMove2CharValue);
						advance(MoveIterator1, 1);
					}
					else
					{
						advance(MoveIterator1, 1);
					}
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

void BaseGameMode::CheckLeftHandValueForUpwardQuadMovement(int LeftHandMoveValue)
{
	//Consider putting all the Boundry Values into a Vector and navigate via that
	if (LeftHandMoveValue >= 0 && LeftHandMoveValue < 8) // Need to Fix, not within bounds
	{
		LeftHandBoundryValue = 0;
	}
	else if (LeftHandMoveValue > 7 && LeftHandMoveValue < 16)
	{
		LeftHandBoundryValue = 0;
	}
	else if (LeftHandMoveValue > 15 && LeftHandMoveValue < 24)
	{
		LeftHandBoundryValue = 8;
	}
	else if (LeftHandMoveValue > 23 && LeftHandMoveValue < 32)
	{
		LeftHandBoundryValue = 16;
	}
	else if (LeftHandMoveValue > 31 && LeftHandMoveValue < 40)
	{
		LeftHandBoundryValue = 24;
	}
	else if (LeftHandMoveValue > 39 && LeftHandMoveValue < 48)
	{
		LeftHandBoundryValue = 32;
	}
	else if (LeftHandMoveValue > 47 && LeftHandMoveValue < 56)
	{
		LeftHandBoundryValue = 40;
	}
	else if (LeftHandMoveValue > 55 && LeftHandMoveValue < 64)
	{
		LeftHandBoundryValue = 48;
	}
}

void BaseGameMode::CheckRightHandValueForUpwardQuadMovement(int RightHandMoveValue)
{
	//Consider putting all the Boundry Values into a Vector and navigate via that
	if (RightHandMoveValue > 0 && RightHandMoveValue < 8) // Need to Fix, not within bounds
	{
		RightHandBoundryValue = 7;
	}
	else if (RightHandMoveValue > 7 && RightHandMoveValue < 16)
	{
		RightHandBoundryValue = 15;
	}
	else if (RightHandMoveValue > 15 && RightHandMoveValue < 24)
	{
		RightHandBoundryValue = 23;
		
	}
	else if (RightHandMoveValue > 23 && RightHandMoveValue < 32)
	{
		RightHandBoundryValue = 31;
		
	}
	else if (RightHandMoveValue > 31 && RightHandMoveValue < 40)
	{
		RightHandBoundryValue = 39;
		
	}
	else if (RightHandMoveValue > 39 && RightHandMoveValue < 48)
	{
		RightHandBoundryValue = 47;
		
	}
	else if (RightHandMoveValue > 47 && RightHandMoveValue < 56)
	{
		RightHandBoundryValue = 55;
		
	}
	else if (RightHandMoveValue > 55 && RightHandMoveValue < 64)
	{
		RightHandBoundryValue = 63;
		
	}
}

void BaseGameMode::CheckDownwardValueforQuadMovement(int SelectedQuad, std::vector<int> SelectedPlayerPieces)
{
	if (SelectedPlayerPieces.at(SelectedQuad) >= 0 && SelectedPlayerPieces.at(SelectedQuad) < 8) // Need to Fix, not within bounds
	{
		LeftHandBoundryValue = 8;
		RightHandBoundryValue = 15;
	}
	else if (SelectedPlayerPieces.at(SelectedQuad) > 7 && SelectedPlayerPieces.at(SelectedQuad) < 16)
	{
		LeftHandBoundryValue = 16;
		RightHandBoundryValue = 23;
	}
	else if (SelectedPlayerPieces.at(SelectedQuad) > 15 && SelectedPlayerPieces.at(SelectedQuad) < 24)
	{
		LeftHandBoundryValue = 24;
		RightHandBoundryValue = 31;
	}
	else if (SelectedPlayerPieces.at(SelectedQuad) > 23 && SelectedPlayerPieces.at(SelectedQuad) < 32)
	{
		LeftHandBoundryValue = 32;
		RightHandBoundryValue = 39;
	}
	else if (SelectedPlayerPieces.at(SelectedQuad) > 31 && SelectedPlayerPieces.at(SelectedQuad) < 40)
	{
		LeftHandBoundryValue = 40;
		RightHandBoundryValue = 47;
	}
	else if (SelectedPlayerPieces.at(SelectedQuad) > 39 && SelectedPlayerPieces.at(SelectedQuad) < 48)
	{
		LeftHandBoundryValue = 48;
		RightHandBoundryValue = 55;
	}
	else if (SelectedPlayerPieces.at(SelectedQuad) > 47 && SelectedPlayerPieces.at(SelectedQuad) < 56)
	{
		LeftHandBoundryValue = 56;
		RightHandBoundryValue = 63;
	}
}

void BaseGameMode::CheckIfLeftHandQuadMoveValueIsOccupied(int SelectedQuad, std::vector<int> FriendlyPieces, std::vector<int> OpponentPieces)
{
	if (IsPlayer1Turn == true) //Does not render correctly, but functions fine 
	{
		for (size_t i = 0; i < PlayerPiecesVectorSize; i++)
		{
			if (SelectedQuadMove1Value == OpponentPieces.at(i))
			{
				SelectedQuadMove1Value = SelectedQuadMove1Value - 9;
				CheckLeftHandValueForUpwardQuadMovement(SelectedQuadMove1Value);
			}
			else if (SelectedQuadMove1Value == FriendlyPieces.at(i))
			{
				SelectedQuadMove1Value = 99; //Might not be smart to do
			}
			else
			{
				CheckLeftHandValueForUpwardQuadMovement(SelectedQuadMove1Value);
			}
		}
	}
	else if (IsPlayer2Turn == true)
	{
		for (size_t i = 0; i < PlayerPiecesVectorSize; i++)
		{
			if (SelectedQuadMove1Value == OpponentPieces.at(i))
			{
				SelectedQuadMove1Value = SelectedQuadMove1Value + 7;
				CheckLeftHandValueForUpwardQuadMovement(SelectedQuadMove1Value);
			}
			else if (SelectedQuadMove1Value == FriendlyPieces.at(i))
			{
				SelectedQuadMove1Value = 99; //Might not be smart to do
			}
			else
			{
				CheckLeftHandValueForUpwardQuadMovement(SelectedQuadMove1Value);
			}
		}
	}

}

void BaseGameMode::CheckIfRightHandQuadMoveValueIsOccupied(int SelectedQuad, std::vector<int> FriendlyPieces, std::vector<int> OpponentPieces)
{
	if (IsPlayer1Turn == true)
	{
		for (size_t i = 0; i < PlayerPiecesVectorSize; i++)
		{
			if (SelectedQuadMove2Value == OpponentPieces.at(i))
			{
				SelectedQuadMove2Value = SelectedQuadMove2Value - 7;
				CheckRightHandValueForUpwardQuadMovement(SelectedQuadMove2Value);
			}
			else if (SelectedQuadMove2Value == FriendlyPieces.at(i))
			{
				SelectedQuadMove2Value = 99; //Might not be smart to do
			}
			else
			{
				CheckRightHandValueForUpwardQuadMovement(SelectedQuadMove2Value);
			}
		}
	}
	else if (IsPlayer2Turn == true) //Does not render correctly, but functions fine 
	{
		for (size_t i = 0; i < PlayerPiecesVectorSize; i++)
		{
			if (SelectedQuadMove2Value == OpponentPieces.at(i))
			{
				SelectedQuadMove2Value = SelectedQuadMove2Value + 9;
				CheckRightHandValueForUpwardQuadMovement(SelectedQuadMove2Value);
			}
			else if (SelectedQuadMove2Value == FriendlyPieces.at(i))
			{
				SelectedQuadMove2Value = 99; //Might not be smart to do
			}
			else
			{
				CheckRightHandValueForUpwardQuadMovement(SelectedQuadMove2Value);
			}
		}
	}
}

void BaseGameMode::MoveSelectedQuadToLeftHandQuad(std::vector<int> SelectedPlayerPieces)
{
	Renderer BoardRenderer;

	if (IsQuadSelectedToMove == true)
	{
		std::vector<CheckerBoardQuads>::iterator MoveIterator2 = QuadStorageVector.begin();
		for (size_t i = 0; i < QuadStorageVector.size(); i++)
		{
			if (i == SelectedQuadMove1Value)
			{
				if (IsPlayer1Turn == true)
				{
					MoveIterator2->PopulateQuadWithPlayer1Symbol(Player1QuadSelectionChars.at(PiecePlaceinVector)); //fixed
				}
				else if (IsPlayer2Turn == true)
				{
					MoveIterator2->PopulateQuadWithPlayer2Symbol(Player2QuadSelectionChars.at(PiecePlaceinVector)); //fixed
				}
				advance(MoveIterator2, 1);
			}
			else if (i == SelectedQuadMove2Value)
			{
				MoveIterator2->PopulateQuadWithBaseSymbol();
				advance(MoveIterator2, 1);
			}
			else if (i == SelectedPlayerPieces.at(PiecePlaceinVector)) //Fixed
			{
				MoveIterator2->PopulateQuadWithBaseSymbol();
				advance(MoveIterator2, 1);
			}
			else
			{
				advance(MoveIterator2, 1);
			}
		}
		if (IsPlayer1Turn == true)
		{
			Player1Pieces.at(PiecePlaceinVector) = SelectedQuadMove1Value; //fixed
			IsPlayer1Turn = false;
			IsPlayer2Turn = true;
		}
		else if (IsPlayer2Turn == true)
		{
			Player2Pieces.at(PiecePlaceinVector) = SelectedQuadMove1Value; //fixed
			IsPlayer1Turn = true;
			IsPlayer2Turn = false;
		}

		IsQuadSelectedToMove = false;
	}
	else
	{
		BoardRenderer.Draw("Please Select a Quad to move!", { 1, 3 });
	}
	IsPieceAtLeftEdgeOfBoard = false;
	IsPieceAtRightEdgeOfBoard = false;
}

void BaseGameMode::MoveSelectedQuadToRightHandQuad(std::vector<int> SelectedPlayerPieces)
{
	Renderer BoardRenderer;
	if (IsQuadSelectedToMove == true)
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
				if (IsPlayer1Turn == true)
				{
					MoveIterator2->PopulateQuadWithPlayer1Symbol(Player1QuadSelectionChars.at(PiecePlaceinVector)); //fix
				}
				else if (IsPlayer2Turn == true)
				{
					MoveIterator2->PopulateQuadWithPlayer2Symbol(Player2QuadSelectionChars.at(PiecePlaceinVector)); //fix
				}

				advance(MoveIterator2, 1);
			}
			else if (i == SelectedPlayerPieces.at(PiecePlaceinVector)) //Fix
			{
				MoveIterator2->PopulateQuadWithBaseSymbol();
				advance(MoveIterator2, 1);
			}
			else
			{
				advance(MoveIterator2, 1);
			}
		}
		if (IsPlayer1Turn == true)
		{
			Player1Pieces.at(PiecePlaceinVector) = SelectedQuadMove2Value; //fix
			IsPlayer1Turn = false;
			IsPlayer2Turn = true;
		}
		else if (IsPlayer2Turn == true)
		{
			Player2Pieces.at(PiecePlaceinVector) = SelectedQuadMove2Value; //fix
			IsPlayer1Turn = true;
			IsPlayer2Turn = false;
		}

		IsQuadSelectedToMove = false;
	}
	else
	{
		BoardRenderer.Draw("Please Select a Quad to move!", { 1, 3 });
	}
	IsPieceAtLeftEdgeOfBoard = false;
	IsPieceAtRightEdgeOfBoard = false;
}

void BaseGameMode::CancelMovement(std::vector<int> SelectedPlayerPieces)
{
	Renderer BoardRenderer;
	if (IsQuadSelectedToMove == true)
	{
		std::vector<CheckerBoardQuads>::iterator MoveIterator2 = QuadStorageVector.begin();
		for (size_t i = 0; i < QuadStorageVector.size(); i++)
		{
			if (i == SelectedQuadMove1Value)
			{
				MoveIterator2->PopulateQuadWithBaseSymbol();
				advance(MoveIterator2, 1);
			}
			else if (i == SelectedQuadMove2Value)
			{
				MoveIterator2->PopulateQuadWithBaseSymbol();
				advance(MoveIterator2, 1);
			}
			else if (i == SelectedPlayerPieces.at(PiecePlaceinVector)) //Fixed
			{
				if (IsPlayer1Turn == true)
				{
					MoveIterator2->PopulateQuadWithPlayer1Symbol(Player1QuadSelectionChars.at(PiecePlaceinVector)); //fixed
				}
				else if (IsPlayer2Turn == true)
				{
					MoveIterator2->PopulateQuadWithPlayer2Symbol(Player2QuadSelectionChars.at(PiecePlaceinVector)); //fixed
				}
				advance(MoveIterator2, 1);
			}
			else
			{
				advance(MoveIterator2, 1);
			}
		}

		IsQuadSelectedToMove = false;
	}
	else
	{
		BoardRenderer.Draw("Please Select a Quad to move!", { 1, 3 });
	}
	IsPieceAtLeftEdgeOfBoard = false;
	IsPieceAtRightEdgeOfBoard = false;
	
}

void BaseGameMode::CheckPlayerTurnWithQuadSetup(int Player1QuadSelection, int Player2QuadSelection)
{
	if (IsPlayer1Turn == true)
	{
		PiecePlaceinVector = Player1QuadSelection;
		Player1MovePieceSetup(Player1QuadSelection);
	}
	else if (IsPlayer2Turn == true)
	{
		PiecePlaceinVector = Player2QuadSelection;
		Player2MovePieceSetup(Player2QuadSelection);
	}
}

void BaseGameMode::CheckIfPieceIsOnLeftEdgeOfBoard()
{
	for (size_t i = 0; i < BoardLeftEdgeCoords.size(); i++)
	{
		if (SelectedQuadValue == BoardLeftEdgeCoords.at(i))
		{
			IsPieceAtLeftEdgeOfBoard = true;
		}
	}
}

void BaseGameMode::CheckIffPieceIsOnRightEdgeOfBoard()
{
	for (size_t i = 0; i < BoardRightEdgeCoords.size(); i++)
	{
		if (SelectedQuadValue == BoardRightEdgeCoords.at(i))
		{
			IsPieceAtRightEdgeOfBoard = true;
		}
	}
}

BaseGameMode::~BaseGameMode()
{

}