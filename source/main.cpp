#include <wiiuse/wpad.h>
#include "CellList.h"

using namespace wsp;

int main(int argc, char **argv) { 
	
	//Game window initialization
	GameWindow gwd;
	gwd.InitVideo();
	
	gwd.SetBackground((GXColor) {211, 211, 211, 255});
	
	WPAD_Init();
	
	CellList test = CellList(7, 7);
	test.SpawnCells(0);
	while(1) { 
	
		WPAD_ScanPads();
		
		if(WPAD_ButtonsDown(WPAD_CHAN_0)&WPAD_BUTTON_HOME)
			break;
		
		test.Draw();
		gwd.Flush();
	}
	
	
}