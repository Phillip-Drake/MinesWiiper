
#include "GamePanel.h"
GamePanel::GamePanel()
{
	game.SpawnCells();
	xPan = 0;
	yPan = 0;
	zoomFactor = 1;
	WPAD_Init();
	WPAD_SetDataFormat(WPAD_CHAN_ALL, WPAD_FMT_BTNS_ACC_IR);
	firstPress = true;
	justPressed = false;
}
GamePanel::~GamePanel()
{
	
}
void GamePanel::Spawn(int rows, int columns, int bombMultiple)
{
	game.SetSize(rows, columns, 0, 0, 200, 200);
	game.SpawnCells();
	zoomFactor = game.GetInitialZoom();
	game.AdjustCells(zoomFactor, xPan, yPan);
	bombAmount = (rows * columns) / 10 * bombMultiple;
}
void GamePanel::Update(u32 pressed, ir_t ir)
{
	if(pressed & WPAD_BUTTON_UP)
	{
		yPan -= 1;
		game.AdjustCells(zoomFactor, xPan, yPan);
	}
	if(pressed & WPAD_BUTTON_DOWN)
	{
		yPan += 1;
		game.AdjustCells(zoomFactor, xPan, yPan);
	}
	if(pressed & WPAD_BUTTON_LEFT)
	{
		xPan -= 1;
		game.AdjustCells(zoomFactor, xPan, yPan);
	}
	if(pressed & WPAD_BUTTON_RIGHT)
	{
		xPan += 1;
		game.AdjustCells(zoomFactor, xPan, yPan);
	}
	if(pressed & WPAD_BUTTON_PLUS)
	{
		zoomFactor += .01;
		game.AdjustCells(zoomFactor, xPan, yPan);
	}
	if(pressed & WPAD_BUTTON_MINUS)
	{
		zoomFactor -= .01;
		game.AdjustCells(zoomFactor, xPan, yPan);
	}
	if(pressed & WPAD_BUTTON_A)
	{
		if(!justPressed)
		{
			if(firstPress)
			{
				game.SpawnBombs(bombAmount);
				firstPress = false;
			}
			game.ClickLastCell();
			switch(game.CheckWinLose())
			{
				case 1: 

					break;
				case 2:

					break;
				default:
					break;
			}
			justPressed = true;
		}
	}
	else if(pressed & WPAD_BUTTON_B)
	{
		if(!justPressed)
		{
			game.FlagLastCell();
			justPressed = true;
		}
	}
	else
	{
		justPressed = false;
	}
	game.OverCell(ir.sx - WSP_POINTER_CORRECTION_X, ir.sy - WSP_POINTER_CORRECTION_Y, zoomFactor);
		
}
void GamePanel::Draw()
{
	game.Draw();
}