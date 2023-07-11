#pragma once

#include <string>
#include <vector>
#include <iterator>



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

	void DrawInt(const int & variable, const Point& position);

	void DrawVector(const std::vector<char>& Vec, const Point& position);

	void DrawVectorInt(const std::vector<int>& Vec, const Point& position, const int& Color);

	void DrawStringVector(const std::vector<std::string>& Vec, const Point& position, const int& Color);

	void Draw2DVector(const std::vector<std::vector<char>>& Vec, const Point& position, const int& Color);

	void Draw2DVectorUI(const std::vector<std::vector<char>>& Vec, const Point& position, const int& HealthBarColor, int VerticleMeasure, int HorizontalMeasure);

	void Draw2DVectorUIHealthBar(const std::vector<std::vector<char>>& Vec, const Point& position, const int& HealthBarColor, int VerticleMeasure, int HorizontalMeasure);

	void DrawCoreButton(const char& CoreButton, const Point& position, const int& Color);

	//void Draw2DObjectVector(const std::vector<std::vector<CheckerBoardQuads>>& Vec, const Point& position);

	void SetTextColor(int Color);

	void DrawVerticleBorder(const std::vector<char>& Vec, const Point& position);

	void DrawHorizontalBorder(const std::vector<char>& Vec, const Point& position);

	//void DrawIterator(const std::vector<CheckerBoardQuads>::iterator& QuadIterator, const Point& position);


};

void InitializeRenderer();