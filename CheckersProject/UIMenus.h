#pragma once
#include <vector>
#include <string>

#include "Renderer.h"


class UIMenus
{

public:

	int SquareButtonMeasure = 3;

	std::vector<std::vector<char>> Button{ SquareButtonMeasure, std::vector<char>(SquareButtonMeasure) };

	char CoreButton;

	int CoreButtonColor;

	int ButtonColor;

	UIMenus();

	void GenerateButton();

	void RenderButton(Renderer &RenderButton, int XCOORD, int YCOORD);

	~UIMenus();

};

