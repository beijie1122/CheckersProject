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

	int PlayerPiecesVectorSize = 12;

	int MoveSelectionValue1 = 9;

	int MoveSelectionValue2 = 7;

	int UpwardMovementLeftMeasure = -9;

	int UpwardMovementRightMeasure = -7;

	int DownwardMovementLeftMeasure = 7;

	int DownwardMovementRightMeasure = 9;

	int SelectedQuadValue;

	int SelectedQuadMove1Value;

	char SelectedQuadMove1CharValue;

	int SelectedQuadMove2Value;

	char SelectedQuadMove2CharValue;

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

	//Gameplay: Moving The Quads 

	void MovementSetup(int SelectedQuad, std::vector<int> SelectedPlayerPieces, int LHValue, int RHValue, int &LHMovementQuadValue, int &RHMovementQuadValue, bool &LHCannotMove, bool &RHCannotMove, std::vector<int> OpponenetPieces);

	void CheckMovementQuadDestinationIsOccupied(int &DestinationQuad, int MovementModifier, bool &CannotMoveBool);

	void CheckFollowingQuadForOccupation(int MovementModifier, int &DestinationQuad, bool &CannotMoveBool);

	int CheckFollowingQuadInt;

	//bool LHCannotMove = false;

	//bool RHCannotMove = false;


	//UI: Menu for Remaining Pieces for P1 & P2 

	int Player1RemainingPieces = 12;

	int Player2RemainingPieces = 12;

	std::vector<std::string> PlayersRemainingPiecesMenu;

	std::string FStreamPlayerRemainingPiecesString{ "PlayerRemainingPiecesTextDoc.txt" };

	std::string FStreamInputString;

	int PlayerRemainingPiecesMenuXCoord =  50;

	int PlayerRemainingPiecesMenuYCoord = 10;

	int Player1RemainingPiecesXCoord;

	int Player1RemainingPiecesYCoord = PlayerRemainingPiecesMenuYCoord + 1;

	int Player2RemainingPiecesXCoord;

	int Player2RemainingPiecesYCoord = PlayerRemainingPiecesMenuYCoord + 3;

	int PlayerPiecesMenuTextLength;

	int FStreamLengthFinderCounter;


	//UI Colors

	int RenderColorPlayer1Pieces = 2;

	int RenderColorPlayer2Pieces = 3;

	int RenderColorBasePieces = 1;

	int RenderColorPrepareToBeTaken = 4;

	int RenderColorSelection = 5;

	int RenderColorDebugMenu = 1;


	//Checking If Quad is Null Vars

	bool IsSelectedQuadNull = false;


	//Cancel Move Function Vars 

	int PlayerPieceReplacementValue;


	//Debug Menu 

	std::vector<std::string> DebugMenuVec{};

	std::string FStreamDebugMenu{ "DebugMenuTextFile.txt" };

	int DebugMenuXCoord = 50;

	int DebugMenuYCord = 15;

	int DebugIntXCoord = 34 + DebugMenuXCoord;


	//Vars for Upward/Downward movement

	bool IsQuadMovingUpward = true;

	char UpwardMovementLeftCharValue = 'A';

	char UpwardMovementRightCharValue = 'D';

	char DownwardMovementLeftCharValue = 'J';

	char DownwardMovementRightCharValue = 'L';


	//Vars for Kinging a quad

	std::vector<int> QuadsForP1PiecePromotion{ 0, 1, 2, 3, 4, 5, 6, 7 };

	std::vector<int> QuadsForP2PiecePromotion{ 56, 57, 58, 59, 60, 61, 62, 63 };


	//Gameplay: MovementRefactor - considering for kinged-quad movement 

	int LHUpwardMovement;

	int RHUpwardMovement;

	int LHDownwardMovement;

	int RHDownwardMovement;

	bool CannotMoveUpwardLH;

	bool CannotMoveUpwardRH;

	bool CannotMoveDownwardLH;

	bool CannotMoveDownwardRH;

	int CheckIfP1PieceIsKingedVar;

	int CheckIfP2PieceIsKingedVar;


	//Gameplay: Board Edge Checks

	std::vector<int> LHBoundryValues{ 0, 8, 16, 24, 32, 40, 48, 56 };

	std::vector<int> RHBoundryValues{ 7, 15, 23, 31, 39, 47, 55, 63 };


	//Functions

	BaseGameMode();

	void MainMenu();

	void InitializeFullBoard();

	void RenderBoard();

	void CheckLeftHandValueForUpwardQuadMovement(int LeftHandMoveValue);

	void CheckRightHandValueForUpwardQuadMovement(int RightHandMoveValue);

	void MoveQuadtoLeftQuad(std::vector<int> SelectedPlayerPieces, int LeftHandMeasure, int RightHandMeasure, int& LHMovementQuadValue, int& RHMovementQuadValue);

	void MoveQuadtoRightQuad(std::vector<int> SelectedPlayerPieces, int LeftHandMeasure, int RightHandMeasure, int& LHMovementQuadValue, int& RHMovementQuadValue);

	void CancelMovementRefactor(std::vector<int> SelectedPlayerPieces, int& LHMovementQuadValue, int& RHMovementQuadValue);

	void CheckPlayerTurnWithQuadSetup(int Player1QuadSelection, int Player2QuadSelection);

	void CheckIfPieceIsOnLeftEdgeOfBoard(int SelectedQuad, std::vector<int> SelectedPlayerPieces);

	void CheckIffPieceIsOnRightEdgeOfBoard(int SelectedQuad, std::vector<int> SelectedPlayerPieces);

	void ResetBoolValues();

	void UpdateVecForPieceCapture(std::vector<int> SelectedPlayerPieces);

	void CheckIfSelectedPieceIsNull(int QuadToBeChecked);

	void FStreamExtractionFunctions(std::string FStreamInput, std::vector<std::string>& FStreamStorageVector);

	void DrawPlayerPiecesRemainingMenu(Renderer RenderMode);

	void UpdateXCordCounterForRender();

	void CheckAndUpdateQuadMovementChars(int LHValue, int RHValue);

	void CheckIfPieceShouldBeKinged(int QuadToBeChecked);

	//void QuadSetupForNonKingedQuads(int PlayerQuadSelection);

	void KingedQuadMovementUnusedQuads(int LHMoveValue, int RHMoveValue);

	~BaseGameMode();


};

