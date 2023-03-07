#include "CellList.h"
#include "Button.h"
#include "MineCounter.h"
class GamePanel
{
	public : 
		GamePanel();
		void Spawn();
		void Update();
		void Draw();
	private :
		CellList game;
		Minecounter timer;
}