#include <wiiuse/wpad.h>
#include "CellList.h"
#include "MainScreen.h"
class GamePanel
{
	public : 
		GamePanel();
		~GamePanel();
		void Spawn(int rows, int columns, int bombMultiple);
		void Update(u32 pressed, ir_t ir);
		void Draw();
	private :
		int xPan, yPan,  bombAmount;
		float zoomFactor;
		bool firstPress, justPressed;
		CellList game;
		MineCounter timer;
};