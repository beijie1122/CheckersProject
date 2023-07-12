#include "BaseGameMode.h"
#include "Renderer.h"
#include "UIElements.h"

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

std::unique_ptr<UIElements> Player1HealthBar = std::make_unique<UIElements>();
std::unique_ptr<UIElements> Player2HealthBar = std::make_unique<UIElements>();

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
	
	Player1HealthBar->PopulateHealthBarBorder();
	Player1HealthBar->PopulateHealthBar();

	Player2HealthBar->PopulateHealthBarBorder();
	Player2HealthBar->PopulateHealthBar();

	UIP1RenderXCoord = RenderXCord.at(0) - 3;
	UIP1RenderYCoord = 5;
	UIP2RenderXCoord = RenderXCord.at(8);
	UIP2RenderYCoord = 5;


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
			BoardRenderer.DrawVectorInt(Player2Pieces, { 1, 1 }, RenderColorPlayer2Pieces);
			BoardRenderer.DrawVectorInt(Player1Pieces, { 1, 2 }, RenderColorPlayer1Pieces);

			Player1HealthBar->CheckAndUpdateHealthBarState(Player1HealthBar->PlayerRemainingPieces);
			Player2HealthBar->CheckAndUpdateHealthBarState(Player2HealthBar->PlayerRemainingPieces);

			Player1HealthBar->RenderHealthBar(BoardRenderer, UIP1RenderXCoord, UIP1RenderYCoord, RenderColorPlayer1Pieces, Player1HealthBar->CurrentHealthBarColor, Player1HealthBar->PlayerRemainingPieces);
			Player2HealthBar->RenderHealthBar(BoardRenderer, UIP2RenderXCoord, UIP2RenderYCoord, RenderColorPlayer2Pieces, Player2HealthBar->CurrentHealthBarColor, Player2HealthBar->PlayerRemainingPieces);


			RenderColorDebugMenu++;

			if (RenderColorDebugMenu == 6)
			{
				RenderColorDebugMenu = 1;
			}

			DrawPlayerPiecesRemainingMenu(BoardRenderer);
			BoardRenderer.DrawStringVector(DebugMenuVec, { DebugMenuXCoord, DebugMenuYCord }, RenderColorDebugMenu);
			BoardRenderer.DrawInt(LHUpwardMovement, { DebugIntXCoord, DebugMenuYCord + 1 });
			BoardRenderer.DrawInt(RHUpwardMovement, { DebugIntXCoord, DebugMenuYCord + 2 });
			BoardRenderer.DrawInt(LHDownwardMovement, { DebugIntXCoord, DebugMenuYCord + 3 });
			BoardRenderer.DrawInt(RHDownwardMovement, { DebugIntXCoord, DebugMenuYCord + 4 });
			BoardRenderer.DrawInt(OpponentPieceToBeTaken, { DebugIntXCoord, DebugMenuYCord + 5 });
			BoardRenderer.DrawInt(LeftHandBoundryValue, { DebugIntXCoord, DebugMenuYCord + 6 });
			BoardRenderer.DrawInt(RightHandBoundryValue, { DebugIntXCoord, DebugMenuYCord + 7 });

			BoardRenderer.DrawInt(StoredLHUpwardMovement, { DebugIntXCoord + 3, DebugMenuYCord + 1 });
			BoardRenderer.DrawInt(StoredRHUpwardMovement, { DebugIntXCoord + 3, DebugMenuYCord + 2 });
			BoardRenderer.DrawInt(StoredLHDownwardMovement, { DebugIntXCoord + 3, DebugMenuYCord + 3 });
			BoardRenderer.DrawInt(StoredRHDownwardMovement, { DebugIntXCoord + 3, DebugMenuYCord + 4 });
			BoardRenderer.DrawInt(OpponentPieceToBeTaken, { DebugIntXCoord + 3, DebugMenuYCord + 5 });
			BoardRenderer.DrawInt(StoredLHBoundryValue, { DebugIntXCoord + 3, DebugMenuYCord + 6 });
			BoardRenderer.DrawInt(StoredRHBoundryValue, { DebugIntXCoord + 3, DebugMenuYCord + 7 });


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


			//Win Conditions 

			if (Player1HealthBar->PlayerRemainingPieces < 1)
			{
				EndGameMenu();
				//break;
			}

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
			else if (IsVirtualKeyPressed(0x4E)) //N Key
			{
				//Testing for win conditions and resetting the game 
				Player1HealthBar->PlayerRemainingPieces = 0;
			}
	
			if (IsVirtualKeyPressed(AKey)) // A Key
			{
				KeyToBePassed = AKey;
				//Will need to mod for when pieces are kinged
				if (IsPlayer1Turn == true && QuadStorageVector.at(CheckIfP1PieceIsKingedVar).IsPieceKinged == true)
				{
					KingedQuadMovementUnusedQuads(LHDownwardMovement, RHDownwardMovement);
					MoveQuadtoLeftQuad(Player1Pieces, UpwardMovementLeftMeasure, UpwardMovementRightMeasure, LHUpwardMovement, RHUpwardMovement);
				}
				else if (IsPlayer1Turn == true)
				{
					MoveQuadtoLeftQuad(Player1Pieces, UpwardMovementLeftMeasure, UpwardMovementRightMeasure, LHUpwardMovement, RHUpwardMovement);
				}
				
			}
			else if (IsVirtualKeyPressed(DKey)) //D key
			{
				KeyToBePassed = DKey;
				//Will need to mod for when pieces are kinged
				if (IsPlayer1Turn == true && QuadStorageVector.at(CheckIfP1PieceIsKingedVar).IsPieceKinged == true)
				{
					KingedQuadMovementUnusedQuads(LHDownwardMovement, RHDownwardMovement);
					MoveQuadtoRightQuad(Player1Pieces, UpwardMovementLeftMeasure, UpwardMovementRightMeasure, LHUpwardMovement, RHUpwardMovement);
				}
				else if (IsPlayer1Turn == true)
				{
					MoveQuadtoRightQuad(Player1Pieces, UpwardMovementLeftMeasure, UpwardMovementRightMeasure, LHUpwardMovement, RHUpwardMovement);
				}
			}
			else if (IsVirtualKeyPressed(JKey)) //J key
			{
				KeyToBePassed = JKey;
				//Will need to mod for when pieces are kinged
				if (IsPlayer2Turn == true)
				{
					MoveQuadtoLeftQuad(Player2Pieces, DownwardMovementLeftMeasure, DownwardMovementRightMeasure, LHDownwardMovement, RHDownwardMovement);
				}
				else if (IsPlayer1Turn == true && QuadStorageVector.at(CheckIfP1PieceIsKingedVar).IsPieceKinged == true)
				{
					KingedQuadMovementUnusedQuads(LHUpwardMovement, RHUpwardMovement);
					MoveQuadtoLeftQuad(Player1Pieces, DownwardMovementLeftMeasure, DownwardMovementRightMeasure, LHDownwardMovement, RHDownwardMovement);
				}
			}
			else if (IsVirtualKeyPressed(LKey))// L key
			{
				KeyToBePassed = LKey;
				//Will need to mod for when pieces are kinged
				if (IsPlayer2Turn == true)
				{
					MoveQuadtoRightQuad(Player2Pieces, DownwardMovementLeftMeasure, DownwardMovementRightMeasure, LHDownwardMovement, RHDownwardMovement);
				}
				else if (IsPlayer1Turn == true && QuadStorageVector.at(CheckIfP1PieceIsKingedVar).IsPieceKinged == true)
				{
					KingedQuadMovementUnusedQuads(LHUpwardMovement, RHUpwardMovement);
					MoveQuadtoRightQuad(Player1Pieces, DownwardMovementLeftMeasure, DownwardMovementRightMeasure, LHDownwardMovement, RHDownwardMovement);
				}
			}

			else if (IsVirtualKeyPressed(0x45)) //E key
			{
				if (IsPlayer1Turn == true)
				{
					//CancelMovement(Player1Pieces);
					CancelMovementRefactor(Player1Pieces, LHUpwardMovement, RHUpwardMovement);
				}
				else if (IsPlayer2Turn == true)
				{
					//CancelMovement(Player2Pieces);
					CancelMovementRefactor(Player2Pieces, LHDownwardMovement, RHDownwardMovement);
				}
			}
	}
}

void BaseGameMode::CheckPlayerTurnWithQuadSetup(int Player1QuadSelection, int Player2QuadSelection)
{
	IsSelectedQuadNull = false;
	
	CheckIfP1PieceIsKingedVar = Player1Pieces.at(Player1QuadSelection);
	CheckIfP2PieceIsKingedVar = Player2Pieces.at(Player2QuadSelection);

	if (IsPlayer1Turn == true && IsQuadSelectedToMove != true && QuadStorageVector.at(CheckIfP1PieceIsKingedVar).IsPieceKinged == true)
	{
		if (CheckIfP1PieceIsKingedVar < 8)
		{
			PiecePlaceinVector = Player1QuadSelection;
			MovementSetup(Player1QuadSelection, Player1Pieces, DownwardMovementLeftMeasure, DownwardMovementRightMeasure, LHDownwardMovement, RHDownwardMovement, CannotMoveDownwardLH, CannotMoveDownwardRH, Player2Pieces);
			//DownwardMovementSetup(Player2QuadSelection);
			IsQuadSelectedToMove = true;
		}
		else if (CheckIfP1PieceIsKingedVar > 55)
		{
			PiecePlaceinVector = Player1QuadSelection;
			MovementSetup(Player1QuadSelection, Player1Pieces, UpwardMovementLeftMeasure, UpwardMovementRightMeasure, LHUpwardMovement, RHUpwardMovement, CannotMoveUpwardLH, CannotMoveUpwardRH, Player2Pieces);
			//UpwardMovementSetup(Player1QuadSelection);
			IsQuadSelectedToMove = true;
		}
		else
		{
			PiecePlaceinVector = Player1QuadSelection;
			MovementSetup(Player1QuadSelection, Player1Pieces, UpwardMovementLeftMeasure, UpwardMovementRightMeasure, LHUpwardMovement, RHUpwardMovement, CannotMoveUpwardLH, CannotMoveUpwardRH, Player2Pieces);
			//UpwardMovementSetup(Player1QuadSelection);
			IsQuadSelectedToMove = true;

			PiecePlaceinVector = Player1QuadSelection;
			MovementSetup(Player1QuadSelection, Player1Pieces, DownwardMovementLeftMeasure, DownwardMovementRightMeasure, LHDownwardMovement, RHDownwardMovement, CannotMoveDownwardLH, CannotMoveDownwardRH, Player2Pieces);
			//DownwardMovementSetup(Player2QuadSelection);
			IsQuadSelectedToMove = true;
		}
	}

	else if (IsPlayer2Turn == true && IsQuadSelectedToMove != true && QuadStorageVector.at(CheckIfP2PieceIsKingedVar).IsPieceKinged == true)
	{

	}


	else if (IsPlayer1Turn == true && IsQuadSelectedToMove != true)
	{
		CheckIfSelectedPieceIsNull(Player1QuadSelection);
			//Check for kings here if this function works
		if (IsSelectedQuadNull != true)
		{
				PiecePlaceinVector = Player1QuadSelection;
				MovementSetup(Player1QuadSelection, Player1Pieces, UpwardMovementLeftMeasure, UpwardMovementRightMeasure, LHUpwardMovement, RHUpwardMovement, CannotMoveUpwardLH, CannotMoveUpwardRH, Player2Pieces);
				//UpwardMovementSetup(Player1QuadSelection);
				IsQuadSelectedToMove = true;
		}

	}
	else if (IsPlayer2Turn == true && IsQuadSelectedToMove != true)
	{
		CheckIfSelectedPieceIsNull(Player2QuadSelection);
		if (IsSelectedQuadNull != true)
		{
			PiecePlaceinVector = Player2QuadSelection;
			MovementSetup(Player2QuadSelection, Player2Pieces, DownwardMovementLeftMeasure, DownwardMovementRightMeasure, LHDownwardMovement, RHDownwardMovement, CannotMoveDownwardLH, CannotMoveDownwardRH, Player1Pieces);
			//DownwardMovementSetup(Player2QuadSelection);
			IsQuadSelectedToMove = true;
		}
	}
}


//
//CheckerBoardQuads& quad1 = QuadStorageVector.at(SelectedQuad);
//CheckerBoardQuads& quad2 = QuadStorageVector.at(SelectedQuad - 9);
//

void BaseGameMode::MovementSetup(int SelectedQuad, std::vector<int> SelectedPlayerPieces, int LHValue, int RHValue, int& LHMovementQuadValue, int& RHMovementQuadValue, bool &LHCannotMove, bool &RHCannotMove, std::vector<int> OpponenetPieces)
{
	SelectedQuadValue = SelectedPlayerPieces.at(SelectedQuad); //Redundant, but needed to work foro the check boundries function atm
	LHMovementQuadValue = SelectedPlayerPieces.at(SelectedQuad) + LHValue;
	CheckMovementQuadDestinationIsOccupied(LHMovementQuadValue, LHValue, LHCannotMove);
	RHMovementQuadValue = SelectedPlayerPieces.at(SelectedQuad) + RHValue;
	CheckMovementQuadDestinationIsOccupied(RHMovementQuadValue, RHValue, RHCannotMove);

	QuadStorageVector.at(SelectedPlayerPieces.at(SelectedQuad)).MoveSelectionQuadFill(SelectedQuadMoveBaseQuadCharValue);
	CheckIfPieceIsOnLeftEdgeOfBoard(SelectedQuad, SelectedPlayerPieces);
	CheckIffPieceIsOnRightEdgeOfBoard(SelectedQuad, SelectedPlayerPieces);

	CheckAndUpdateQuadMovementChars(LHValue, RHValue);

	if (LHMovementQuadValue >= LeftHandBoundryValue && IsPieceAtLeftEdgeOfBoard == false && LHCannotMove == false)
	{
		QuadStorageVector.at(LHMovementQuadValue).MoveSelectionQuadFill(SelectedQuadMove1CharValue);
	}
	if (RHMovementQuadValue <= RightHandBoundryValue && IsPieceAtRightEdgeOfBoard == false && RHCannotMove == false)
	{
		QuadStorageVector.at(RHMovementQuadValue).MoveSelectionQuadFill(SelectedQuadMove2CharValue);
	}
	if (BLHUpwardOpponentPiece == true)
	{
		QuadStorageVector.at(LHUpwardOpponentPiece).PopulateQuadWithPrepareToBeTaken();
	}
	
	if (BRHUpwardOpponentPiece == true)
	{
		QuadStorageVector.at(RHUpwardOpponentPiece).PopulateQuadWithPrepareToBeTaken();
	}
	
	if (BLHDownwardOpponentPiece == true)
	{
		QuadStorageVector.at(LHDownwardOpponentPiece).PopulateQuadWithPrepareToBeTaken();
	}
	
	if (BRHDownwardOpponentPiece == true)
	{
		QuadStorageVector.at(RHDownwardOpponentPiece).PopulateQuadWithPrepareToBeTaken();
	}

	IsQuadSelectedToMove = true;

}


void BaseGameMode::CheckMovementQuadDestinationIsOccupied(int &DestinationQuad, int MovementModifier, bool &CannotMoveBool)
{
	if (IsPlayer1Turn == true)
	{
		if (QuadStorageVector.at(DestinationQuad).IsPlayer2Quad == true)
		{
			//Checks if piece is at top/bottom edges of board
			if (DestinationQuad > 7 && DestinationQuad < 56)
			{
				//OpponentPieceToBeTaken = DestinationQuad;

				AssignOpponentPiecePlacement(MovementModifier, DestinationQuad);

				char SavedCharacter;
				
				for (int i = 0; i < PlayerPiecesVectorSize; i++)
				{
					if (DestinationQuad == Player2Pieces.at(i))
					{
						TakenPieceIndexinPiecesQuad = i;
					}
				}
				//IsOpponentsPieceToBeTaken = true;
				CheckFollowingQuadForOccupation(MovementModifier, DestinationQuad, CannotMoveBool);
			}

			else
			{
				CannotMoveBool = true;
			}

		}
		else if (QuadStorageVector.at(DestinationQuad).IsPlayer1Quad == true)
		{
			CannotMoveBool = true;
		}
		else
		{
			if (MovementModifier == UpwardMovementLeftMeasure || MovementModifier == DownwardMovementLeftMeasure)
			{
				CheckLeftHandValueForUpwardQuadMovement(DestinationQuad);
			}
			else
			{
				CheckRightHandValueForUpwardQuadMovement(DestinationQuad);
			}
		}
	}
	else
	{
		if (QuadStorageVector.at(DestinationQuad).IsPlayer1Quad == true)
		{
			//Checks if piece is at LH/RH edges of board
			if (DestinationQuad > 7 && DestinationQuad < 56)
			{
				//OpponentPieceToBeTaken = DestinationQuad;

				AssignOpponentPiecePlacement(MovementModifier, DestinationQuad);
				for (int i = 0; i < PlayerPiecesVectorSize; i++)
				{
					if (DestinationQuad == Player1Pieces.at(i))
					{
						TakenPieceIndexinPiecesQuad = i;
					}
				}
				//IsOpponentsPieceToBeTaken = true;
				CheckFollowingQuadForOccupation(MovementModifier, DestinationQuad, CannotMoveBool);
			}
			else
			{
				CannotMoveBool = true;
			}
		}
		else if (QuadStorageVector.at(DestinationQuad).IsPlayer2Quad == true)
		{
			CannotMoveBool = true;
		}
		else
		{
			if (MovementModifier == UpwardMovementLeftMeasure || MovementModifier == DownwardMovementLeftMeasure)
			{
				CheckLeftHandValueForUpwardQuadMovement(DestinationQuad);
			}
			else
			{
				CheckRightHandValueForUpwardQuadMovement(DestinationQuad);
			}
		}
	}
}

void BaseGameMode::AssignOpponentPiecePlacement(int ValueToBeChecked, int& DestinationQuad)
{
	if (ValueToBeChecked == UpwardMovementLeftMeasure)
	{
		LHUpwardOpponentPiece = DestinationQuad;
		BLHUpwardOpponentPiece = true;
	}
	else if (ValueToBeChecked == UpwardMovementRightMeasure)
	{
		RHUpwardOpponentPiece = DestinationQuad;
		BRHUpwardOpponentPiece = true;
	}
	else if (ValueToBeChecked == DownwardMovementLeftMeasure)
	{
		LHDownwardOpponentPiece = DestinationQuad;
		BLHDownwardOpponentPiece = true;
	}
	else
	{
		RHDownwardOpponentPiece = DestinationQuad;
		BRHDownwardOpponentPiece = true;
	}

}


void BaseGameMode::CheckFollowingQuadForOccupation(int MovementModifier, int& DestinationQuad, bool &CannotMoveBool)
{
	CheckFollowingQuadInt = DestinationQuad + MovementModifier;
	if (QuadStorageVector.at(CheckFollowingQuadInt).IsPlayer1Quad == true || QuadStorageVector.at(CheckFollowingQuadInt).IsPlayer2Quad == true)
	{
		CannotMoveBool = true;
		//Also Check for Edges
	}
	else
	{
		DestinationQuad = DestinationQuad + MovementModifier;
		if (MovementModifier == UpwardMovementLeftMeasure || MovementModifier == DownwardMovementLeftMeasure)
		{
			CheckLeftHandValueForUpwardQuadMovement(DestinationQuad);
		}
		else
		{
			CheckRightHandValueForUpwardQuadMovement(DestinationQuad);
		}
	}
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

void BaseGameMode::MoveQuadtoLeftQuad(std::vector<int> SelectedPlayerPieces, int LeftHandMeasure, int RightHandMeasure, int& LHMovementQuadValue, int& RHMovementQuadValue)
{
	if (IsPlayer1Turn == true)
	{
		QuadStorageVector.at(LHMovementQuadValue).PopulateQuadWithPlayer1Symbol(Player1QuadSelectionChars.at(PiecePlaceinVector));
		{
			if (QuadStorageVector.at(SelectedPlayerPieces.at(PiecePlaceinVector)).IsPieceKinged == true)
			{
				QuadStorageVector.at(SelectedPlayerPieces.at(PiecePlaceinVector)).IsPieceKinged = false;
				QuadStorageVector.at(LHMovementQuadValue).IsPieceKinged = true;
			}
		}
		CheckIfPieceShouldBeKinged(LHMovementQuadValue);
	}
	else
	{
		QuadStorageVector.at(LHMovementQuadValue).PopulateQuadWithPlayer2Symbol(Player2QuadSelectionChars.at(PiecePlaceinVector));
		CheckIfPieceShouldBeKinged(LHMovementQuadValue);
	}

	if (QuadStorageVector.at(RHMovementQuadValue).IsPlayer1Quad == true)
	{

	}
	else if (QuadStorageVector.at(RHMovementQuadValue).IsPlayer2Quad == true)
	{

	}
	else
	{
		QuadStorageVector.at(RHMovementQuadValue).PopulateQuadWithBaseSymbol();
	}

	if (KeyToBePassed == AKey && BLHUpwardOpponentPiece == true)
	{
		QuadStorageVector.at(LHUpwardOpponentPiece).PopulateQuadWithBaseSymbol();
		UpdateVecForPieceCapture(SelectedPlayerPieces);
	}
	else if (KeyToBePassed == JKey && BLHDownwardOpponentPiece == true)
	{
		QuadStorageVector.at(LHDownwardOpponentPiece).PopulateQuadWithBaseSymbol();
		UpdateVecForPieceCapture(SelectedPlayerPieces);
	}

	if (BRHUpwardOpponentPiece == true)
	{
		if (IsPlayer1Turn == true)
		{
			//UPDATE - This One is sort of working 
			QuadStorageVector.at(RHUpwardOpponentPiece).PopulateQuadWithPlayer2Symbol(QuadStorageVector.at(RHUpwardOpponentPiece).SavedQuadAssignedChar);
		}
		else
		{
			//UPDATE
			QuadStorageVector.at(RHUpwardOpponentPiece).PopulateQuadWithPlayer1Symbol(Player1QuadSelectionChars.at(2));
		}
	}

	if (BRHDownwardOpponentPiece == true)
	{
		if (IsPlayer1Turn == true)
		{
			//UPDATE
			QuadStorageVector.at(RHDownwardOpponentPiece).PopulateQuadWithPlayer2Symbol(Player2QuadSelectionChars.at(2));
		}
		else
		{
			//UPDATE
			QuadStorageVector.at(RHDownwardOpponentPiece).PopulateQuadWithPlayer1Symbol(Player1QuadSelectionChars.at(2));
		}
	}


	/*
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
	*/

	QuadStorageVector.at(SelectedPlayerPieces.at(PiecePlaceinVector)).PopulateQuadWithBaseSymbol();


	if (IsPlayer1Turn == true)
	{
		Player1Pieces.at(PiecePlaceinVector) = LHMovementQuadValue; //fixed
		IsPlayer1Turn = false;
		IsPlayer2Turn = true;
	}
	else if (IsPlayer2Turn == true)
	{
		Player2Pieces.at(PiecePlaceinVector) = LHMovementQuadValue; //fixed -- might be broken, need to switch to RH
		IsPlayer1Turn = true;
		IsPlayer2Turn = false;
	}
	IsQuadSelectedToMove = false;
	ResetBoolValues();
}

void BaseGameMode::MoveQuadtoRightQuad(std::vector<int> SelectedPlayerPieces, int LeftHandMeasure, int RightHandMeasure, int& LHMovementQuadValue, int& RHMovementQuadValue)
{
	//QuadStorageVector.at(SelectedQuadMove1Value).PopulateQuadWithBaseSymbol();

	if (QuadStorageVector.at(LHMovementQuadValue).IsPlayer1Quad == true)
	{

	}
	else if (QuadStorageVector.at(LHMovementQuadValue).IsPlayer2Quad == true)
	{

	}
	else
	{
		QuadStorageVector.at(LHMovementQuadValue).PopulateQuadWithBaseSymbol();
	}

	if (IsPlayer1Turn == true)
	{
		QuadStorageVector.at(RHMovementQuadValue).PopulateQuadWithPlayer1Symbol(Player1QuadSelectionChars.at(PiecePlaceinVector));
		if (QuadStorageVector.at(SelectedPlayerPieces.at(PiecePlaceinVector)).IsPieceKinged == true)
		{
			QuadStorageVector.at(SelectedPlayerPieces.at(PiecePlaceinVector)).IsPieceKinged = false;
			QuadStorageVector.at(RHMovementQuadValue).IsPieceKinged = true;
		}
		CheckIfPieceShouldBeKinged(RHMovementQuadValue);
	}
	else
	{
		QuadStorageVector.at(RHMovementQuadValue).PopulateQuadWithPlayer2Symbol(Player2QuadSelectionChars.at(PiecePlaceinVector));
		CheckIfPieceShouldBeKinged(RHMovementQuadValue);
	}

	if (KeyToBePassed == DKey && BRHUpwardOpponentPiece == true)
	{
		QuadStorageVector.at(RHUpwardOpponentPiece).PopulateQuadWithBaseSymbol();
		UpdateVecForPieceCapture(SelectedPlayerPieces);
	}
	else if (KeyToBePassed == JKey && BRHDownwardOpponentPiece == true)
	{
		QuadStorageVector.at(RHDownwardOpponentPiece).PopulateQuadWithBaseSymbol();
		UpdateVecForPieceCapture(SelectedPlayerPieces);
	}

	if (BLHUpwardOpponentPiece == true)
	{
		if (IsPlayer1Turn == true)
		{
			//UPDATE
			QuadStorageVector.at(LHUpwardOpponentPiece).PopulateQuadWithPlayer2Symbol(Player2QuadSelectionChars.at(2));
		}
		else
		{
			//UPDATE
			QuadStorageVector.at(LHUpwardOpponentPiece).PopulateQuadWithPlayer1Symbol(Player1QuadSelectionChars.at(2));
		}
	}

	if (BLHDownwardOpponentPiece == true)
	{
		if (IsPlayer1Turn == true)
		{
			//UPDATE
			QuadStorageVector.at(LHDownwardOpponentPiece).PopulateQuadWithPlayer2Symbol(Player2QuadSelectionChars.at(2));
		}
		else
		{
			//UPDATE
			QuadStorageVector.at(LHDownwardOpponentPiece).PopulateQuadWithPlayer1Symbol(Player1QuadSelectionChars.at(2));
		}
	}


	/*
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
	*/
	QuadStorageVector.at(SelectedPlayerPieces.at(PiecePlaceinVector)).PopulateQuadWithBaseSymbol();


	if (IsPlayer1Turn == true)
	{
		Player1Pieces.at(PiecePlaceinVector) = RHMovementQuadValue; //fixed
		IsPlayer1Turn = false;
		IsPlayer2Turn = true;
	}
	else if (IsPlayer2Turn == true)
	{
		Player2Pieces.at(PiecePlaceinVector) = RHMovementQuadValue; //fixed -- might be broken, need to switch to LH
		IsPlayer1Turn = true;
		IsPlayer2Turn = false;
	}

	IsQuadSelectedToMove = false;
	ResetBoolValues();
}

void BaseGameMode::KingedQuadMovementUnusedQuads(int LHMoveValue, int RHMoveValue)
{
	if (QuadStorageVector.at(LHMoveValue).IsPlayer1Quad != true && QuadStorageVector.at(LHMoveValue).IsPlayer2Quad != true)
	{
		QuadStorageVector.at(LHMoveValue).PopulateQuadWithBaseSymbol();
	}

	if (QuadStorageVector.at(RHMoveValue).IsPlayer1Quad != true && QuadStorageVector.at(RHMoveValue).IsPlayer2Quad != true)
	{
		QuadStorageVector.at(RHMoveValue).PopulateQuadWithBaseSymbol();
	}

}



void BaseGameMode::CancelMovementRefactor(std::vector<int> SelectedPlayerPieces, int& LHMovementQuadValue, int& RHMovementQuadValue)
{
	Renderer BoardRenderer;
	if (IsQuadSelectedToMove == true)
	{
		if (QuadStorageVector.at(LHMovementQuadValue).IsPlayer1Quad == true)
		{
			for (int i = 0; i < PlayerPiecesVectorSize; i++)
			{
				if (LHMovementQuadValue == Player1Pieces.at(i))
				{
					QuadStorageVector.at(LHMovementQuadValue).PopulateQuadWithPlayer1Symbol(Player1QuadSelectionChars.at(i));
				}
			}
			
		}
		else if (QuadStorageVector.at(LHMovementQuadValue).IsPlayer2Quad == true)
		{
			for (int i = 0; i < PlayerPiecesVectorSize; i++)
			{
				if (LHMovementQuadValue == Player2Pieces.at(i))
				{
					QuadStorageVector.at(LHMovementQuadValue).PopulateQuadWithPlayer2Symbol(Player2QuadSelectionChars.at(i));
				}
			}
		}
		else
		{
			QuadStorageVector.at(LHMovementQuadValue).PopulateQuadWithBaseSymbol();
		}
		
		if (QuadStorageVector.at(RHMovementQuadValue).IsPlayer1Quad == true)
		{
			for (int i = 0; i < PlayerPiecesVectorSize; i++)
			{
				if (RHMovementQuadValue == Player1Pieces.at(i))
				{
					QuadStorageVector.at(RHMovementQuadValue).PopulateQuadWithPlayer1Symbol(Player1QuadSelectionChars.at(i));
				}
			}

		}
		else if (QuadStorageVector.at(RHMovementQuadValue).IsPlayer2Quad == true)
		{
			for (int i = 0; i < PlayerPiecesVectorSize; i++)
			{
				if (RHMovementQuadValue == Player2Pieces.at(i))
				{
					QuadStorageVector.at(RHMovementQuadValue).PopulateQuadWithPlayer2Symbol(Player2QuadSelectionChars.at(i));
				}
			}
		}
		else
		{
			QuadStorageVector.at(RHMovementQuadValue).PopulateQuadWithBaseSymbol();
		}

		

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

void BaseGameMode::CheckIfPieceIsOnLeftEdgeOfBoard(int SelectedQuad, std::vector<int> SelectedPlayerPieces)
{
	for (size_t i = 0; i < BoardLeftEdgeCoords.size(); i++)
	{
		if (SelectedQuadValue == BoardLeftEdgeCoords.at(i))
		{
			IsPieceAtLeftEdgeOfBoard = true;
		}
	}
}

void BaseGameMode::CheckIffPieceIsOnRightEdgeOfBoard(int SelectedQuad, std::vector<int> SelectedPlayerPieces)
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
	CannotMoveUpwardLH = false;
	CannotMoveUpwardRH = false;
	CannotMoveDownwardLH = false;
	CannotMoveDownwardRH = false;
	//IsQuadMovingUpward = false;

	StoredLHUpwardMovement = LHUpwardMovement;
	StoredRHUpwardMovement = RHUpwardMovement;
	StoredLHDownwardMovement = LHDownwardMovement;
	StoredRHDownwardMovement = RHDownwardMovement;
	StoredLHBoundryValue = LeftHandBoundryValue;
	StoredRHBoundryValue = RightHandBoundryValue;


	LHUpwardMovement = 0;
	RHUpwardMovement = 0;
	LHDownwardMovement = 0;
	RHDownwardMovement = 0;
	LeftHandBoundryValue = 0;
	RightHandBoundryValue = 0;
	OpponentPieceToBeTaken = 0;

	BLHUpwardOpponentPiece = false;
	BRHUpwardOpponentPiece = false;
	BLHDownwardOpponentPiece = false;
	BRHDownwardOpponentPiece = false;

}

void BaseGameMode::UpdateVecForPieceCapture(std::vector<int> SelectedPlayerPieces)
{
	if (SelectedPlayerPieces == Player1Pieces)
	{
		Player2Pieces.at(TakenPieceIndexinPiecesQuad) = NULL;
		Player2RemainingPieces--;
		Player2HealthBar->PlayerRemainingPieces--;
	}
	else
	{
		Player1Pieces.at(TakenPieceIndexinPiecesQuad) = NULL;
		Player1RemainingPieces--;
		Player1HealthBar->PlayerRemainingPieces--;
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
	RenderMode.DrawStringVector(PlayersRemainingPiecesMenu, { PlayerRemainingPiecesMenuXCoord, PlayerRemainingPiecesMenuYCoord }, 6);
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

void BaseGameMode::CheckAndUpdateQuadMovementChars(int LHValue, int RHValue)
{
	if (LHValue == UpwardMovementLeftMeasure && RHValue == UpwardMovementRightMeasure)
	{
		SelectedQuadMove1CharValue = UpwardMovementLeftCharValue;

		SelectedQuadMove2CharValue = UpwardMovementRightCharValue;

		//IsQuadMovingUpward = true;
	}
	else
	{
		SelectedQuadMove1CharValue = DownwardMovementLeftCharValue;

		SelectedQuadMove2CharValue = DownwardMovementRightCharValue;

		//IsQuadMovingUpward = false;
	}
}

void BaseGameMode::CheckIfPieceShouldBeKinged(int QuadToBeChecked)
{
	if (QuadStorageVector.at(QuadToBeChecked).IsPlayer1Quad == true)
	{
		for (int i = 0; i < 8; i++)
		{
			if (QuadToBeChecked == QuadsForP1PiecePromotion.at(i))
			{
				QuadStorageVector.at(QuadToBeChecked).IsPieceKinged = true;
			}
		}
		QuadStorageVector.at(QuadToBeChecked).PopulateQuadWithPlayer1Symbol(Player1QuadSelectionChars.at(PiecePlaceinVector));
	}
	else if (QuadStorageVector.at(QuadToBeChecked).IsPlayer2Quad == true)
	{
		for (int i = 0; i < 8; i++)
		{
			if (QuadToBeChecked == QuadsForP2PiecePromotion.at(i))
			{
				QuadStorageVector.at(QuadToBeChecked).IsPieceKinged = true;
			}
		}
		QuadStorageVector.at(QuadToBeChecked).PopulateQuadWithPlayer2Symbol(Player2QuadSelectionChars.at(PiecePlaceinVector));
	}
}

void BaseGameMode::StartGameMenu()
{
	FStreamExtractionFunctions(FStreamStartMenuButton, StartMenuButtonTextVec);
	std::unique_ptr<UIMenus>Button1 = std::make_unique<UIMenus>();
	ButtonStorageVector.push_back(*Button1);
	std::unique_ptr<UIMenus>Button2 = std::make_unique<UIMenus>();
	ButtonStorageVector.push_back(*Button2);
	std::unique_ptr<UIMenus>Button3 = std::make_unique<UIMenus>();
	ButtonStorageVector.push_back(*Button3);
	std::unique_ptr<UIMenus>Button4 = std::make_unique<UIMenus>();
	ButtonStorageVector.push_back(*Button4);
	
	while (true)
	{

		ButtonStorageVector.at(CurrentlySelectedMenuButton).CoreButtonColor = 4;

		Renderer RenderMode;

		RenderMode.DrawMenuString("Press 0 to make a selection", { XCOORD, YCOORDVector.at(0) - 3 }, BasicTextColor);
		RenderMode.DrawMenuString("Press W to move up, press S to move down", { XCOORD, YCOORDVector.at(0) - 2 }, BasicTextColor);

		for (int i = 0; i < ButtonStorageVector.size(); i++)
		{
			ButtonStorageVector.at(i).RenderButton(RenderMode, XCOORD, YCOORDVector.at(i));
		}

		for (int i = 0; i < StartMenuButtonTextVec.size(); i++)
		{
			RenderMode.DrawMenuString(StartMenuButtonTextVec.at(i), { XCOORD + 4, YCOORDVector.at(i) + 1 }, BasicTextColor);
		}

	
		if (IsVirtualKeyPressed(VK_NUMPAD0))
		{
			if (CurrentlySelectedMenuButton == 0)
			{
				MainMenu();
			}
			else if (CurrentlySelectedMenuButton == 1)
			{
				for (int i = 0; i < ButtonStorageVector.size(); i++)
				{
					ButtonStorageVector.at(i).ButtonColor = 4;
				}
			}
			else if (CurrentlySelectedMenuButton == 2)
			{
				for (int i = 0; i < ButtonStorageVector.size(); i++)
				{
					ButtonStorageVector.at(i).CoreButtonColor = 5;
				}
			}
			else if (CurrentlySelectedMenuButton == 3)
			{
				for (int i = 0; i < ButtonStorageVector.size(); i++)
				{
					ButtonStorageVector.at(i).ButtonColor = 2;
					ButtonStorageVector.at(i).CoreButtonColor = 3;
				}
			}	
		}
		else if (IsVirtualKeyPressed(WKey))
		{
			if (CurrentlySelectedMenuButton != 0)
			{
				ButtonStorageVector.at(CurrentlySelectedMenuButton).CoreButtonColor = 3;
				CurrentlySelectedMenuButton--;
			}
		}
		else if (IsVirtualKeyPressed(SKey))
		{

			if (CurrentlySelectedMenuButton != 3)
			{
				ButtonStorageVector.at(CurrentlySelectedMenuButton).CoreButtonColor = 3;
				CurrentlySelectedMenuButton++;
			}
		}
	}
}

void BaseGameMode::EndGameMenu()
{
	
	while (true)
	{
		Renderer RenderMode;
		RenderMode.Draw("Please Press 0 to return to Start Menu", { 25, 25 });
		
		if (IsVirtualKeyPressed(VK_NUMPAD0))
		{
			break;
		}
	}
}

BaseGameMode::~BaseGameMode()
{

}