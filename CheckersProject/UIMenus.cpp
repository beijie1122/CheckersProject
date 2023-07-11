#include "UIMenus.h"

UIMenus::UIMenus()
{
	ButtonColor = 2;
	CoreButtonColor = 3;
	GenerateButton();
}

void UIMenus::GenerateButton()
{
	Button[0][0] = 201;
	Button[0][1] = 205;
	Button[0][2] = 187;
	Button[1][0] = 186;
	Button[1][1] = 219;
	Button[1][2] = 186;
	Button[2][0] = 200;
	Button[2][1] = 205;
	Button[2][2] = 188;

	CoreButton = 219;

}

void UIMenus::RenderButton(Renderer& RenderButton, int XCOORD, int YCOORD)
{
	RenderButton.Draw2DVector(Button, { XCOORD, YCOORD}, ButtonColor);
	RenderButton.DrawCoreButton(CoreButton, { XCOORD + 1, YCOORD + 1 }, CoreButtonColor);
}

UIMenus::~UIMenus()
{

}