#pragma once

#include <iostream>
#include <vector>

#include "Renderer.h"

class UIElements
{

public:

	int QuadSizeVerticle = 14;

	int QuadSizeHorizontal = 3;

	int HealthBarQuadSizeHorizontal = 1;

	int HealthBarQuadSizeVerticle = 12;

	int PlayerRemainingPieces = 12;

	int UIHealthBarHealthyColor = 2;

	int UIHealthBarMidColor = 6;

	int UIHealthBarDangerColor = 4;

	int CurrentHealthBarColor;

	std::vector<std::vector<char>> HealthBarBorder{ QuadSizeVerticle, std::vector<char>(QuadSizeHorizontal) };

	std::vector<std::vector<char>> HealthBar{ QuadSizeVerticle, std::vector<char>(HealthBarQuadSizeHorizontal) };

	UIElements();

	void PopulateHealthBarBorder();

	void PopulateHealthBar();

	void CheckAndUpdateHealthBarState(int PlayerRemainingPieces);

	void RenderHealthBar(Renderer &RenderHealthBar, int UIXCOORD, int UIYCOORD, int PlayerColor, int HealthBarColor, int PlayerRemainingPieces);

	~UIElements();


};

