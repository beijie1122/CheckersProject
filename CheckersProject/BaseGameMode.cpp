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
#include <fstream>

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
		FStreamExtractionFunctions(FStreamPlayerRemainingPiecesString, PlayersRemainingPiecesMenu);
		FStreamExtractionFunctions(FStreamDebugMenu, DebugMenuVec);
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

		int XCordCounter = 0;

		for (size_t i = 0; i < QuadStorageVector.size(); i++)
		{
			if (i < 8)
			{
				QuadStorageVector.at(i).RenderQuad(BoardRenderer, RenderXCord.at(XCordCounter), RenderYCord.at(0));
				XCordCounter++;
			}
			else if (i >= 8 && i < 16)
			{
				if (XCordCounter > 7)
				{
					XCordCounter = 0;
				}
				QuadStorageVector.at(i).RenderQuad(BoardRenderer, RenderXCord.at(XCordCounter), RenderYCord.at(1));
				XCordCounter++;

			}
			else if (i >= 16 && i < 24)
			{
				if (XCordCounter > 7)
				{
					XCordCounter = 0;
				}
				QuadStorageVector.at(i).RenderQuad(BoardRenderer, RenderXCord.at(XCordCounter), RenderYCord.at(2));
				XCordCounter++;
			}
			else if (i >= 24 && i < 32)
			{
				if (XCordCounter > 7)
				{
					XCordCounter = 0;
				}
				QuadStorageVector.at(i).RenderQuad(BoardRenderer, RenderXCord.at(XCordCounter), RenderYCord.at(3));
				XCordCounter++;
			}
			else if (i >= 32 && i < 40)
			{
				if (XCordCounter > 7)
				{
					XCordCounter = 0;
				}
				QuadStorageVector.at(i).RenderQuad(BoardRenderer, RenderXCord.at(XCordCounter), RenderYCord.at(4));
				XCordCounter++;
			}
			else if (i >= 40 && i < 48)
			{
				if (XCordCounter > 7)
				{
					XCordCounter = 0;
				}
				QuadStorageVector.at(i).RenderQuad(BoardRenderer, RenderXCord.at(XCordCounter), RenderYCord.at(5));
				XCordCounter++;
			}
			else if (i >= 48 && i < 56)
			{
				if (XCordCounter > 7)
				{
					XCordCounter = 0;
				}
				QuadStorageVector.at(i).RenderQuad(BoardRenderer, RenderXCord.at(XCordCounter), RenderYCord.at(6));
				XCordCounter++;
			}
			else if (i >= 56 && i < 64)
			{
				if (XCordCounter > 7)
				{
					XCordCounter = 0;
				}
				QuadStorageVector.at(i).RenderQuad(BoardRenderer, RenderXCord.at(XCordCounter), RenderYCord.at(7));
				XCordCounter++;
			}
		}
			BoardRenderer.DrawVectorInt(Player2Pieces, { 1, 1 }, RenderColorPlayer1Pieces);
			BoardRenderer.DrawVectorInt(Player1Pieces, { 1, 2 }, 6);

			RenderColorPlayer1Pieces++;

			if (RenderColorPlayer1Pieces == 6)
			{
				RenderColorPlayer1Pieces = 1;
			}

			DrawPlayerPiecesRemainingMenu(BoardRenderer);
			BoardRenderer.DrawStringVector(DebugMenuVec, { DebugMenuXCoord, DebugMenuYCord });
			BoardRenderer.DrawInt(SelectedQuadMove1Value, { DebugIntXCoord, DebugMenuYCord + 1 });
			BoardRenderer.DrawInt(SelectedQuadMove2Value, { DebugIntXCoord, DebugMenuYCord + 2 });
			BoardRenderer.DrawInt(OpponentPieceToBeTaken, { DebugIntXCoord, DebugMenuYCord + 4 });
			BoardRenderer.DrawInt(LeftHandBoundryValue, { DebugIntXCoord, DebugMenuYCord + 5 });
			BoardRenderer.DrawInt(RightHandBoundryValue, { DebugIntXCoord, DebugMenuYCord + 6 });


			if (IsPlayer1Turn == true)
			{
				BoardRenderer.Draw("Player 1's Turn!", { 50, 1 });
			}
			else if (IsPlayer2Turn == true)
			{
				BoardRenderer.Draw("Player 2's Turn!", { 50, 1 });
			}

			if (IsSelectedQuadNull == true)
			{
				BoardRenderer.Draw("Sorry, the piece you have selected is already taken!", { 50, 2 });
			}

			//DrawPlayerPiecesRemainingMenu(BoardRenderer);
			if (IsQuadSelectedToMove == false)
			{
				BoardRenderer.Draw("Select A Quad", { 1, 4 });
			}
			else if (IsQuadSelectedToMove == true)
			{
				BoardRenderer.Draw("Select where to move the quad", { 1, 4 });
			}

			BoardRenderer.DrawInt(LeftHandBoundryValue, { 40, 1 });   

			//Test for UI Length Value 
			//BoardRenderer.DrawInt(PlayerPiecesMenuTextLength, { 40, 3 });
		
			
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
					MoveQuadtoLeftQuad(Player1Pieces, UpwardMovementLeftMeasure, UpwardMovementRightMeasure);
				}
				else if (IsPlayer2Turn == true)
				{
					MoveQuadtoLeftQuad(Player2Pieces, DownwardMovementLeftMeasure, DownwardMovementRightMeasure);
				}
				
			}
			else if (IsVirtualKeyPressed(0x44)) //D key
			{
				if (IsPlayer1Turn == true)
				{
					MoveQuadtoRightQuad(Player1Pieces, UpwardMovementLeftMeasure, UpwardMovementRightMeasure);
				}
				else if (IsPlayer2Turn == true)
				{
					MoveQuadtoRightQuad(Player2Pieces, DownwardMovementLeftMeasure, DownwardMovementRightMeasure);
				}
			}
			else if (IsVirtualKeyPressed(0x45)) //E key
			{
				if (IsPlayer1Turn == true)
				{
					//CancelMovement(Player1Pieces);
					CancelMovementRefactor(Player1Pieces);
				}
				else if (IsPlayer2Turn == true)
				{
					//CancelMovement(Player2Pieces);
					CancelMovementRefactor(Player2Pieces);
				}
			}
	}
}

void BaseGameMode::CheckPlayerTurnWithQuadSetup(int Player1QuadSelection, int Player2QuadSelection)
{
	IsSelectedQuadNull = false;

	if (IsQuadSelectedToMove != true)
	{
		if (IsPlayer1Turn == true)
		{
			CheckIfSelectedPieceIsNull(Player1QuadSelection);
			if (IsSelectedQuadNull != true)
			{
				PiecePlaceinVector = Player1QuadSelection;
				UpwardMovementSetup(Player1QuadSelection);
				IsQuadSelectedToMove = true;
			}

		}
		else if (IsPlayer2Turn == true)
		{
			CheckIfSelectedPieceIsNull(Player2QuadSelection);
			if (IsSelectedQuadNull != true)
			{
				PiecePlaceinVector = Player2QuadSelection;
				DownwardMovementSetup(Player2QuadSelection);
				IsQuadSelectedToMove = true;
			}
		}
	}

}

//
//CheckerBoardQuads& quad1 = QuadStorageVector.at(SelectedQuad);
//CheckerBoardQuads& quad2 = QuadStorageVector.at(SelectedQuad - 9);
//



void BaseGameMode::UpwardMovementSetup(int SelectedQuad)
{
	SelectedQuadValue = Player1Pieces.at(SelectedQuad);
	SelectedQuadMove1Value = SelectedQuadValue - 9;
	CheckIfLeftHandQuadMoveValueIsOccupied(SelectedQuad, Player1Pieces, Player2Pieces);
	SelectedQuadMove2Value = SelectedQuadValue - 7;
	CheckIfRightHandQuadMoveValueIsOccupied(SelectedQuad, Player1Pieces, Player2Pieces);

	QuadStorageVector.at(Player1Pieces.at(SelectedQuad)).MoveSelectionQuadFill(SelectedQuadMoveBaseQuadCharValue);
	CheckIfPieceIsOnLeftEdgeOfBoard();
	CheckIffPieceIsOnRightEdgeOfBoard();

	if (SelectedQuadMove1Value >= LeftHandBoundryValue && IsPieceAtLeftEdgeOfBoard == false)
	{
		QuadStorageVector.at(SelectedQuadMove1Value).MoveSelectionQuadFill(SelectedQuadMove1CharValue);
	}
	if (SelectedQuadMove2Value <= RightHandBoundryValue && IsPieceAtRightEdgeOfBoard == false)
	{
		QuadStorageVector.at(SelectedQuadMove2Value).MoveSelectionQuadFill(SelectedQuadMove2CharValue);
	}
	if (IsOpponentsPieceToBeTaken == true)
	{
		QuadStorageVector.at(OpponentPieceToBeTaken).PopulateQuadWithPrepareToBeTaken();
	}
	IsQuadSelectedToMove = true;

}


void BaseGameMode::DownwardMovementSetup(int SelectedQuad)
{
	SelectedQuadValue = Player2Pieces.at(SelectedQuad);
	SelectedQuadMove1Value = SelectedQuadValue + 7;
	CheckIfLeftHandQuadMoveValueIsOccupied(SelectedQuad, Player2Pieces, Player1Pieces);
	SelectedQuadMove2Value = SelectedQuadValue + 9;
	CheckIfRightHandQuadMoveValueIsOccupied(SelectedQuad, Player2Pieces, Player1Pieces);

	QuadStorageVector.at(Player2Pieces.at(SelectedQuad)).MoveSelectionQuadFill(SelectedQuadMoveBaseQuadCharValue);
	CheckIfPieceIsOnLeftEdgeOfBoard();
	CheckIffPieceIsOnRightEdgeOfBoard();

	if (SelectedQuadMove1Value >= LeftHandBoundryValue && IsPieceAtLeftEdgeOfBoard == false)
	{
		QuadStorageVector.at(SelectedQuadMove1Value).MoveSelectionQuadFill(SelectedQuadMove1CharValue);
	}
	if (SelectedQuadMove2Value <= RightHandBoundryValue && IsPieceAtRightEdgeOfBoard == false)
	{
		QuadStorageVector.at(SelectedQuadMove2Value).MoveSelectionQuadFill(SelectedQuadMove2CharValue);
	}
	if (IsOpponentsPieceToBeTaken == true)
	{
		QuadStorageVector.at(OpponentPieceToBeTaken).PopulateQuadWithPrepareToBeTaken();
	}
	IsQuadSelectedToMove = true;

}

void BaseGameMode::CheckLeftHandValueForUpwardQuadMovement(int LeftHandMoveValue) 
{
	//Consider putting all the Boundry Values into a Vector and navigate via that
	if (LeftHandMoveValue >= 0 && LeftHandMoveValue < 8) 
	{
		LeftHandBoundryValue = 0;
	}
	else if (LeftHandMoveValue > 7 && LeftHandMoveValue < 16)
	{
		LeftHandBoundryValue = 8;
	}
	else if (LeftHandMoveValue > 15 && LeftHandMoveValue < 24)
	{
		LeftHandBoundryValue = 16;
	}
	else if (LeftHandMoveValue > 23 && LeftHandMoveValue < 32)
	{
		LeftHandBoundryValue = 24;
	}
	else if (LeftHandMoveValue > 31 && LeftHandMoveValue < 40)
	{
		LeftHandBoundryValue = 32;
	}
	else if (LeftHandMoveValue > 39 && LeftHandMoveValue < 48)
	{
		LeftHandBoundryValue = 40;
	}
	else if (LeftHandMoveValue > 47 && LeftHandMoveValue < 56)
	{
		LeftHandBoundryValue = 48;
	}
	else if (LeftHandMoveValue > 55 && LeftHandMoveValue < 64)
	{
		LeftHandBoundryValue = 56;
	}
}

void BaseGameMode::CheckRightHandValueForUpwardQuadMovement(int RightHandMoveValue)
{
	//Consider putting all the Boundry Values into a Vector and navigate via that
	if (RightHandMoveValue > 0 && RightHandMoveValue < 8) 
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
				IsOpponentsPieceToBeTaken = true;
				OpponentPieceToBeTaken = OpponentPieces.at(i);
				TakenPieceIndexinPiecesQuad = i;
			}
			else if (SelectedQuadMove1Value == FriendlyPieces.at(i))
			{
				SelectedQuadMove1Value = 0; //Might not be smart to do
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
				IsOpponentsPieceToBeTaken = true;
				OpponentPieceToBeTaken = OpponentPieces.at(i);
				TakenPieceIndexinPiecesQuad = i;
			}
			else if (SelectedQuadMove1Value == FriendlyPieces.at(i))
			{
				SelectedQuadMove1Value = 0; //Might not be smart to do
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
				IsOpponentsPieceToBeTaken = true;
				OpponentPieceToBeTaken = OpponentPieces.at(i);
				TakenPieceIndexinPiecesQuad = i;
			}
			else if (SelectedQuadMove2Value == FriendlyPieces.at(i))
			{
				SelectedQuadMove2Value = 0; //Might not be smart to do
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
				IsOpponentsPieceToBeTaken = true;
				OpponentPieceToBeTaken = OpponentPieces.at(i);
				TakenPieceIndexinPiecesQuad = i;
			}
			else if (SelectedQuadMove2Value == FriendlyPieces.at(i))
			{
				SelectedQuadMove2Value = 0; //Might not be smart to do
			}
			else
			{
				CheckRightHandValueForUpwardQuadMovement(SelectedQuadMove2Value);
			}
		}
	}
}

void BaseGameMode::MoveQuadtoLeftQuad(std::vector<int> SelectedPlayerPieces, int LeftHandMeasure, int RightHandMeasure)
{
	if (IsPlayer1Turn == true)
	{
		QuadStorageVector.at(SelectedQuadMove1Value).PopulateQuadWithPlayer1Symbol(Player1QuadSelectionChars.at(PiecePlaceinVector));
	}
	else
	{
		QuadStorageVector.at(SelectedQuadMove1Value).PopulateQuadWithPlayer2Symbol(Player2QuadSelectionChars.at(PiecePlaceinVector));
	}

	QuadStorageVector.at(SelectedQuadMove2Value).PopulateQuadWithBaseSymbol();

	if (OpponentPieceToBeTaken == SelectedPlayerPieces.at(PiecePlaceinVector) + LeftHandMeasure)
	{
		QuadStorageVector.at(OpponentPieceToBeTaken).PopulateQuadWithBaseSymbol();
		UpdateVecForPieceCapture(SelectedPlayerPieces);
	}
	else if (OpponentPieceToBeTaken == SelectedPlayerPieces.at(PiecePlaceinVector) + RightHandMeasure)
	{
		if (SelectedPlayerPieces == Player1Pieces)
		{
			QuadStorageVector.at(OpponentPieceToBeTaken).PopulateQuadWithPlayer2Symbol(Player2QuadSelectionChars.at(TakenPieceIndexinPiecesQuad));
		}
		else
		{
			QuadStorageVector.at(OpponentPieceToBeTaken).PopulateQuadWithPlayer1Symbol(Player1QuadSelectionChars.at(TakenPieceIndexinPiecesQuad));
		}
	}

	QuadStorageVector.at(SelectedPlayerPieces.at(PiecePlaceinVector)).PopulateQuadWithBaseSymbol();


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
	ResetBoolValues();
}



void BaseGameMode::MoveQuadtoRightQuad(std::vector<int> SelectedPlayerPieces, int LeftHandMeasure, int RightHandMeasure)
{
	QuadStorageVector.at(SelectedQuadMove1Value).PopulateQuadWithBaseSymbol();

	if (IsPlayer1Turn == true)
	{
		QuadStorageVector.at(SelectedQuadMove2Value).PopulateQuadWithPlayer1Symbol(Player1QuadSelectionChars.at(PiecePlaceinVector));
	}
	else
	{
		QuadStorageVector.at(SelectedQuadMove2Value).PopulateQuadWithPlayer2Symbol(Player2QuadSelectionChars.at(PiecePlaceinVector));
	}


	if (OpponentPieceToBeTaken == SelectedPlayerPieces.at(PiecePlaceinVector) + RightHandMeasure)
	{
		QuadStorageVector.at(OpponentPieceToBeTaken).PopulateQuadWithBaseSymbol();
		UpdateVecForPieceCapture(SelectedPlayerPieces);
	}
	else if (OpponentPieceToBeTaken == SelectedPlayerPieces.at(PiecePlaceinVector) + LeftHandMeasure)
	{
		if (SelectedPlayerPieces == Player1Pieces)
		{
			QuadStorageVector.at(OpponentPieceToBeTaken).PopulateQuadWithPlayer2Symbol(Player2QuadSelectionChars.at(TakenPieceIndexinPiecesQuad));
		}
		else
		{
			QuadStorageVector.at(OpponentPieceToBeTaken).PopulateQuadWithPlayer1Symbol(Player1QuadSelectionChars.at(TakenPieceIndexinPiecesQuad));
		}
	}

	QuadStorageVector.at(SelectedPlayerPieces.at(PiecePlaceinVector)).PopulateQuadWithBaseSymbol();


	if (IsPlayer1Turn == true)
	{
		Player1Pieces.at(PiecePlaceinVector) = SelectedQuadMove2Value; //fixed
		IsPlayer1Turn = false;
		IsPlayer2Turn = true;
	}
	else if (IsPlayer2Turn == true)
	{
		Player2Pieces.at(PiecePlaceinVector) = SelectedQuadMove2Value; //fixed
		IsPlayer1Turn = true;
		IsPlayer2Turn = false;
	}

	IsQuadSelectedToMove = false;
	ResetBoolValues();
}

void BaseGameMode::CancelMovementRefactor(std::vector<int> SelectedPlayerPieces)
{
	Renderer BoardRenderer;
	if (IsQuadSelectedToMove == true)
	{
		QuadStorageVector.at(SelectedQuadMove1Value).PopulateQuadWithBaseSymbol();
		QuadStorageVector.at(SelectedQuadMove2Value).PopulateQuadWithBaseSymbol();

		if (IsPlayer1Turn == true)
		{
			QuadStorageVector.at(SelectedPlayerPieces.at(PiecePlaceinVector)).PopulateQuadWithPlayer1Symbol(Player1QuadSelectionChars.at(PiecePlaceinVector));
		}
		else
		{
			QuadStorageVector.at(SelectedPlayerPieces.at(PiecePlaceinVector)).PopulateQuadWithPlayer2Symbol(Player2QuadSelectionChars.at(PiecePlaceinVector));
		}

		if (IsOpponentsPieceToBeTaken == true && IsPlayer1Turn == true)
		{
			QuadStorageVector.at(OpponentPieceToBeTaken).PopulateQuadWithPlayer2Symbol(Player2QuadSelectionChars.at(TakenPieceIndexinPiecesQuad));
		}
		else if (IsOpponentsPieceToBeTaken == true && IsPlayer2Turn == true)
		{
			QuadStorageVector.at(OpponentPieceToBeTaken).PopulateQuadWithPlayer1Symbol(Player1QuadSelectionChars.at(TakenPieceIndexinPiecesQuad));
		}

		IsQuadSelectedToMove = false;
	}
	else
	{
		BoardRenderer.Draw("Please Select a Quad to move!", { 1, 3 });
	}

	ResetBoolValues();
}

void BaseGameMode::CheckIfSelectedPieceIsNull(int QuadToBeChecked)
{
	if (IsPlayer1Turn == true && Player1Pieces.at(QuadToBeChecked) == NULL)
	{
			IsSelectedQuadNull = true;
			return;
	}
	else if (IsPlayer2Turn == true && Player2Pieces.at(QuadToBeChecked) == NULL)
	{
			IsSelectedQuadNull = true;
			return;
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

void BaseGameMode::ResetBoolValues()
{
	IsPieceAtLeftEdgeOfBoard = false;
	IsPieceAtRightEdgeOfBoard = false;
	IsOpponentsPieceToBeTaken = false;

}

void BaseGameMode::UpdateVecForPieceCapture(std::vector<int> SelectedPlayerPieces)
{
	if (SelectedPlayerPieces == Player1Pieces)
	{
		Player2Pieces.at(TakenPieceIndexinPiecesQuad) = NULL;
		Player2RemainingPieces--;
	}
	else
	{
		Player1Pieces.at(TakenPieceIndexinPiecesQuad) = NULL;
		Player1RemainingPieces--;
	}
}

void BaseGameMode::FStreamExtractionFunctions(std::string FStreamInput, std::vector<std::string>& FStreamStorageVector)
{
	std::ifstream in_file;
	in_file.open(FStreamInput);
	if (!in_file)
	{
		return;
	}
	else
	{
		if (in_file.is_open())
		{
			while (std::getline(in_file, FStreamInputString))
			{
				if (FStreamLengthFinderCounter != 1)
				{
					FStreamStorageVector.emplace_back(FStreamInputString);
					FStreamLengthFinderCounter++;
				}
				else
				{
					PlayerPiecesMenuTextLength = FStreamInputString.size();
					FStreamStorageVector.emplace_back(FStreamInputString);
					FStreamLengthFinderCounter++;
				}
				
			}
		}
	}
	Player1RemainingPiecesXCoord = PlayerRemainingPiecesMenuXCoord + PlayerPiecesMenuTextLength;

	Player2RemainingPiecesXCoord = PlayerRemainingPiecesMenuXCoord + PlayerPiecesMenuTextLength;

	in_file.close();
}

void BaseGameMode::DrawPlayerPiecesRemainingMenu(Renderer RenderMode)
{
	RenderMode.DrawStringVector(PlayersRemainingPiecesMenu, { PlayerRemainingPiecesMenuXCoord, PlayerRemainingPiecesMenuYCoord });
	RenderMode.DrawInt(Player1RemainingPieces, { Player1RemainingPiecesXCoord, Player1RemainingPiecesYCoord });
	RenderMode.DrawInt(Player2RemainingPieces, { Player2RemainingPiecesXCoord, Player2RemainingPiecesYCoord });
}

void BaseGameMode::UpdateXCordCounterForRender()
{
	//if (XCordCounter > 7)
	//{
	//	XCordCounter = 0;
	//}
}

BaseGameMode::~BaseGameMode()
{

}