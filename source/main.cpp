#include <wiiuse/wpad.h>
#include "CellList.h"

using namespace wsp;
Sprite cursor;
Image cursorImage;
int main(int argc, char **argv) { 
	
	//Game window initialization
	GameWindow gwd;
	gwd.InitVideo();
	bool justPressed = false, firstPress = true;
	gwd.SetBackground((GXColor) {211, 211, 211, 255});
	
	WPAD_Init();
	WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);
	
	CellList test = CellList(24, 20);
	test.SpawnCells();
	cursorImage.LoadImage(cursor_png, IMG_LOAD_TYPE_BUFFER);
	cursor.SetImage(&cursorImage);
	while(1) { 
	
		WPAD_ScanPads();
		u32 pressed = WPAD_ButtonsHeld(WPAD_CHAN_0);
		
		if(WPAD_ButtonsDown(WPAD_CHAN_0)&WPAD_BUTTON_HOME)
			break;
		
		
		
		ir_t ir;
		WPAD_IR(WPAD_CHAN_0, &ir);
		cursor.SetPosition(ir.sx - WSP_POINTER_CORRECTION_X, ir.sy - WSP_POINTER_CORRECTION_Y);
		cursor.Move(-((f32)cursor.GetWidth()/2), -((f32)cursor.GetHeight()/2));
		cursor.SetRotation(ir.angle/2);
		
		if(pressed & WPAD_BUTTON_A)
		{
			if(!justPressed)
			{
				if(firstPress)
				{
					test.SpawnBombs(50);
					firstPress = false;
				}
				test.ClickLastCell();
				justPressed = true;
			}
		}
		else if(pressed && WPAD_BUTTON_B)
		{
			if(!justPressed)
			{
				test.FlagLastCell();
				justPressed = true;
			}
		}
		else
		{
			justPressed = false;
		}
		test.OverCell(ir.sx - WSP_POINTER_CORRECTION_X, ir.sy - WSP_POINTER_CORRECTION_Y);
		
		
		test.Draw();
		cursor.Draw();
		gwd.Flush();
	}
	
	
}