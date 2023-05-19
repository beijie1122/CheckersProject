#pragma once

#include <string>
#include <vector>
#include <iterator>
#include "CheckerBoardQuads.h"


//Defines a point/cord
struct Point
{
	int x;
	int y;
};

struct Rect
{
	int left;
	int top;
	int right;
	int bottom;
};

class Renderer
{

public:

	Renderer();

	~Renderer();

	void Draw(const std::string& text, const Point& position);

	void DrawVector(const std::vector<char>& Vec, const Point& position);

	void DrawStringVector(const std::vector<std::string>& Vec, const Point& position);

	void Draw2DVector(const std::vector<std::vector<char>>& Vec, const Point& position);

	void DrawVerticleBorder(const std::vector<char>& Vec, const Point& position);

	void DrawHorizontalBorder(const std::vector<char>& Vec, const Point& position);

	//void DrawIterator(const std::vector<CheckerBoardQuads>::iterator& QuadIterator, const Point& position);


};

void InitializeRenderer();