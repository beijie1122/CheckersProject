#include "UIElements.h"

UIElements::UIElements()
{

}

void UIElements::PopulateHealthBarBorder()
{
	for (int i = 0; i < QuadSizeVerticle; i++)
	{
		for (int j = 0; j < QuadSizeHorizontal; j++)
		{
			if (j == 1 && i != 0 && i != 13)
			{
				HealthBarBorder[i][j] = ' ';
			}
			else
			{
				HealthBarBorder[i][j] = 219;
			}
		}
	}
}

void UIElements::PopulateHealthBar()
{
	for (int i = 0; i < PlayerRemainingPieces; i++)
	{
		for (int j = 0; j < HealthBarQuadSizeHorizontal; j++)
		{
			HealthBar[i][j] = 219;
		}
	}
}

void UIElements::RenderHealthBar(Renderer& RenderHealthBar, int UIXCOORD, int UIYCOORD, int PlayerColor, int HealthBarColor, int PlayerRemainingPieces)
{

	RenderHealthBar.Draw2DVectorUI(HealthBarBorder, { UIXCOORD, UIYCOORD },  PlayerColor, QuadSizeVerticle, QuadSizeHorizontal);
	RenderHealthBar.Draw2DVectorUIHealthBar(HealthBar, { UIXCOORD + 1, UIYCOORD + 12 }, HealthBarColor, PlayerRemainingPieces, HealthBarQuadSizeHorizontal);
}

void UIElements::CheckAndUpdateHealthBarState(int PlayerRemainingPieces)
{
	if (PlayerRemainingPieces > 8)
	{
		CurrentHealthBarColor = UIHealthBarHealthyColor;
	}
	else if (PlayerRemainingPieces < 9 && PlayerRemainingPieces > 4)
	{
		CurrentHealthBarColor = UIHealthBarMidColor;
	}
	else
	{
		CurrentHealthBarColor = UIHealthBarDangerColor;
	}
}

UIElements::~UIElements()
{

}