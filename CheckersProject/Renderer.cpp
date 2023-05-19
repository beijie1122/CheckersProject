#include "Renderer.h"
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <conio.h>
#include <thread>
#include <string>


Renderer::Renderer()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	LockWindowUpdate(GetConsoleWindow());
	system("CLS");
}

Renderer::~Renderer()
{
	//Only let it clear once 
	LockWindowUpdate(NULL);
}

bool SetCursorToPosition(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Renderer::Draw(const std::string& text, const Point& position)
{
	SetCursorToPosition(position.x, position.y);
	std::cout << text;
}

void Renderer::DrawVector(const std::vector<char>& Vec, const Point& position)
{
	SetCursorToPosition(position.x, position.y);
	for (size_t i = 0; i < Vec.size(); i++)
	{
		std::cout << Vec.at(i);
	}
}

void Renderer::DrawStringVector(const std::vector<std::string>& Vec, const Point& position)
{
	int IterateY = 0;
	SetCursorToPosition(position.x, position.y);
	for (size_t i = 0; i < Vec.size(); i++)
	{
		std::cout << Vec.at(i);
		IterateY++;
		SetCursorToPosition(position.x, position.y + IterateY);
	}
}

//Edit to pass vec sizes
void Renderer::Draw2DVector(const std::vector<std::vector<char>>& Vec, const Point& position)
{
	int IterateY = 0;
	SetCursorToPosition(position.x, position.y);
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			std::cout << Vec[i][j];
		}
		IterateY++;
		SetCursorToPosition(position.x, position.y + IterateY);
	}

}

void Renderer::DrawVerticleBorder(const std::vector<char>& Vec, const Point& position)
{
	SetCursorToPosition(position.x, position.y);
	for (size_t i = 0; i < Vec.size(); i++)
	{
		std::cout << Vec.at(i);
	}

}

void Renderer::DrawHorizontalBorder(const std::vector<char>& Vec, const Point& position)
{
	int IterateY = 0;
	SetCursorToPosition(position.x, position.y);
	for (size_t i = 0; i < Vec.size(); i++)
	{
		std::cout << Vec.at(i);
		IterateY++;
		SetCursorToPosition(position.x, position.y + IterateY);
	}
}

//void Renderer::DrawIterator(const std::vector<CheckerBoardQuads>::iterator& QuadIterator, const Point& position)
//{
//	int IterateY = 0;
//	SetCursorToPosition(position.x, position.y);
	//for (size_t i = 0; i < 3; i++)
	//{
	//	for (size_t j = 0; j < 3; j++)
	//	{
	//		std::cout << QuadIterator->Quadrant[i][j];
	//	}
	//	IterateY++;
	//	SetCursorToPosition(position.x, position.y + IterateY);
//	}
//	QuadIterator->RenderQuadrant();
//}



void InitializeRenderer()
{

	system("COLOR 8F");
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;

	//Hides the cursor
	SetConsoleCursorInfo(hOut, &ConCurInf);
}
