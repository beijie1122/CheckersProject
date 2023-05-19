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

	char QuadNumber = '0';

	char BaseSymbol{ '~' };

	std::vector<std::vector<char>> Quadrant{ QuadSize, std::vector<char>(QuadSize) };

	CheckerBoardQuads();

	CheckerBoardQuads(char QuadNum);

	void PopulateQuadWithBaseSymbol();

	~CheckerBoardQuads();


};

