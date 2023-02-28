#include <wiiuse/wpad.h>
#include "CellList.h"
#include "MainScreen.h"
using namespace wsp;
Sprite cursor;
Image cursorImage;
int main(int argc, char **argv) {
	float zoomFactor = 1;
	int xPan = 0, yPan = 0;
	//Game window initialization
	GameWindow gwd;
	gwd.InitVideo();
	gwd.SetBackground((GXColor) {211, 211, 211, 255});
	//WiiPad initiation, allows for user input
	WPAD_Init();
	WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);
	//MainScreen intiialization
	MainScreen begin = MainScreen();
	//Game initialization
	CellList game = CellList();
	game.SpawnCells();
	//initialization for cursor sprite
	cursorImage.LoadImage(cursor_png, IMG_LOAD_TYPE_BUFFER);
	cursor.SetImage(&cursorImage);
	//booleans for a-press protection, these will be used to disallow for the user to hold down the a button and press many cells
	bool justPressed = false, firstPress = true;
	//game state stuff
	bool gameRunning = false, splashScreen = true, gameStart = true;
	while(1) {
		//checks for any wii-motes
		WPAD_ScanPads();
		//value for button being pressed
		u32 pressed = WPAD_ButtonsHeld(WPAD_CHAN_0);
		//if the home button is pressed,
		if(WPAD_ButtonsDown(WPAD_CHAN_0)&WPAD_BUTTON_HOME)
			break;



		ir_t ir;
		WPAD_IR(WPAD_CHAN_0, &ir);
		cursor.SetPosition(ir.sx - WSP_POINTER_CORRECTION_X, ir.sy - WSP_POINTER_CORRECTION_Y);
		cursor.Move(-((f32)cursor.GetWidth()/2), -((f32)cursor.GetHeight()/2));
		cursor.SetRotation(ir.angle/2);
		if(gameRunning)
		{
			if(gameStart)
			{
				game.SetSize(begin.GetWidth(), begin.GetHeight());
				game.SpawnCells();
				gameStart = false;
				zoomFactor = game.GetInitialZoom();
				game.AdjustCells(zoomFactor, xPan, yPan);
			}
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
						//((begin.GetWidth() * begin.GetHeight()) / 10) * begin.GetMines()
						game.SpawnBombs(((begin.GetWidth() * begin.GetHeight()) / 10) * begin.GetMines());
						firstPress = false;
					}
					game.ClickLastCell();
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
			game.OverCell(ir.sx - WSP_POINTER_CORRECTION_X, ir.sy - WSP_POINTER_CORRECTION_Y);
			game.Draw();
		}
		else if(splashScreen)
		{
			if(pressed & WPAD_BUTTON_A)
			{
				if(!justPressed)
				{
					if(begin.Click())
						gameRunning = true;
					justPressed = true;
				}
			}
			else
				justPressed = false;
			begin.Update(ir.sx - WSP_POINTER_CORRECTION_X, ir.sy - WSP_POINTER_CORRECTION_Y);
		}
		cursor.Draw();
		gwd.Flush();
	}


}