#include "Cell.h"
#include "Explosion.h"
using namespace wsp;
class CellList{

	public :
		CellList();
		~CellList();
		//sets the size of the cellList
		void SetSize(int rows, int columns, int minX, int minY, int maxX, int maxY);
		void SpawnCells();
		float GetInitialZoom();
		void AdjustCells(float zoomFactor, int xpan, int yPan);
		void SpawnBombs(int BombAmount);
		void Draw();
		void OverCell(int x, int y, float zoomFactor);
		void ClickLastCell();
		void FlagLastCell();
		void RecursiveClick(int row, int col);
		int CheckWinLose();
		void Lose();
	private :
		Cell** cells;	
		int rows, columns, minRow, minCol, maxRow, maxCol, minX, minY, maxX, maxY;
		int lastCell[2];
		Image unClickedCell, highlightedCell, mineCell, flaggedCell, zeroCell, oneCell, twoCell, threeCell, fourCell, fiveCell, sixCell, sevenCell, eightCell;
		bool hasLost;
		Explosion loseExplosion;
};