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

	std::vector<char> InitNums{'1', '2', '3', '4', '5', '6', '7', '8', '9'};

	std::vector<CheckerBoardQuads> QuadStorageVector ;

	std::vector<std::vector<char>> TempVectorForRendering{ QuadSize, std::vector<char>(QuadSize) };

	std::vector<int> RenderXCord{ 5, 9, 13, 17, 21, 25, 29, 33, 37, 41 };

	std::vector<int> RenderYCord{ 5, 8, 11, 14, 17, 20, 23, 26, 29, 32 };

	std::vector<int> Player1Pieces{};
	
	std::vector<int> Player2Pieces{};

	int PlayerPiecesVectorSize = 11;

	int MoveSelectionValue1 = 9;

	int MoveSelectionValue2 = 7;

	int UpwardMovementLeftMeasure = -9;

	int UpwardMovementRightMeasure = -7;

	int DownwardMovementLeftMeasure = 7;

	int DownwardMovementRightMeasure = 9;

	int SelectedQuadValue;

	int SelectedQuadMove1Value;

	char SelectedQuadMove1CharValue{ 'A' };

	int SelectedQuadMove2Value;

	char SelectedQuadMove2CharValue{ 'D' };

	char SelectedQuadMoveBaseQuadCharValue{ 'E' };

	int RenderYCordAdjust{ 0 };

	bool IsQuadSelectedToMove = false;

	int OldQuadPlace{};

	int PiecePlaceinVector{};

	std::vector<char> Player1QuadSelectionChars{ '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'O', 'P' };

	int Player1QuadSelectionCharsVariable{ 0 };

	std::vector<char> Player2QuadSelectionChars{ 'P', 'O', '0', '9', '8', '7', '6', '5', '4', '3', '2', '1'};

	std::vector<int> BoardLeftEdgeCoords{ 0, 8, 16, 24, 32, 40, 48, 56 };

	std::vector<int> BoardRightEdgeCoords{ 7, 15, 23, 31, 39, 47, 55, 63 };

	int Player2QuadSelectionCharsVariable{ 0 };

	int LeftHandBoundryValue{};

	int RightHandBoundryValue{};

	bool IsPlayer1Turn = true;

	bool IsPlayer2Turn = false;

	bool IsPieceAtLeftEdgeOfBoard = false;

	bool IsPieceAtRightEdgeOfBoard = false;

	bool IsOpponentsPieceToBeTaken = false;

	bool IsOpponentsPieceToBeTakenLeft = false;

	bool IsOpponentsPieceToBeTakenRight = false;

	int OpponentPieceToBeTaken{};

	int TakenPieceIndexinPiecesQuad;

	//UI: Menu for Remaining Pieces for P1 & P2 

	int Player1RemainingPieces = 12;

	int Player2RemainingPieces = 12;

	std::vector<std::string> PlayersRemainingPiecesMenu;

	std::string FStreamPlayerRemainingPiecesString{ "PlayerRemainingPiecesTextDoc.txt" };

	std::string FStreamInputString;

	int PlayerRemainingPiecesMenuXCoord =  40;

	int PlayerRemainingPiecesMenuYCoord = 10;

	int Player1RemainingPiecesXCoord;

	int Player1RemainingPiecesYCoord = PlayerRemainingPiecesMenuYCoord + 1;

	int Player2RemainingPiecesXCoord;

	int Player2RemainingPiecesYCoord = PlayerRemainingPiecesMenuYCoord + 3;

	int PlayerPiecesMenuTextLength;

	int FStreamLengthFinderCounter;

	//Checking If Quad is Null Vars

	bool IsSelectedQuadNull = false;

	//Cancel Move Function Vars 

	int PlayerPieceReplacementValue;


	BaseGameMode();

	void MainMenu();

	void InitializeFullBoard();

	void RenderBoard();

	void Player1MovePieceSetup(int SelectedQuad);

	void Player2MovePieceSetup(int SelectedQuad);

	void CheckLeftHandValueForUpwardQuadMovement(int LeftHandMoveValue);

	void CheckRightHandValueForUpwardQuadMovement(int RightHandMoveValue);

	void CheckIfLeftHandQuadMoveValueIsOccupied(int SelectedQuad, std::vector<int> FriendlyPieces, std::vector<int> OpponentPieces);

	void CheckIfRightHandQuadMoveValueIsOccupied(int SelectedQuad, std::vector<int> FriendlyPieces, std::vector<int> OpponentPieces);

	void MoveSelectedQuadToLeftHandQuad(std::vector<int> SelectedPlayerPieces, int LeftHandMeasure, int RightHandMeasure);

	void MoveSelectedQuadToRightHandQuad(std::vector<int> SelectedPlayerPieces, int LeftHandMeasure, int RightHandMeasure);

	void CancelMovement(std::vector<int> SelectedPlayerPieces);

	void CheckPlayerTurnWithQuadSetup(int Player1QuadSelection, int Player2QuadSelection);

	void CheckIfPieceIsOnLeftEdgeOfBoard();

	void CheckIffPieceIsOnRightEdgeOfBoard();

	void ResetBoolValues();

	void UpdateVecForPieceCapture(std::vector<int> SelectedPlayerPieces);

	void CheckIfSelectedPieceIsNull(int QuadToBeChecked);

	void FStreamExtractionFunctions(std::string FStreamInput, std::vector<std::string>& FStreamStorageVector);

	void DrawPlayerPiecesRemainingMenu(Renderer RenderMode);

	~BaseGameMode();


};

