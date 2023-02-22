#include "Cell.h"
using namespace wsp;
class CellList{

	public :
		CellList();
		~CellList();
		//sets the size of the cellList
		void SetSize(int rows, int columns);
		void SpawnCells();
		void AdjustCells(float zoomFactor, int xpan, int yPan);
		void SpawnBombs(int BombAmount);
		void ResetList();
		void Draw();
		void OverCell(int x, int y);
		void ClickLastCell();
		void FlagLastCell();
		void RecursiveClick(int row, int col);
	private :
		Cell** cells;	
		int rows, columns;
		int lastCell[2];
		Image unClickedCell, highlightedCell, mineCell, flaggedCell, zeroCell, oneCell, twoCell, threeCell, fourCell, fiveCell, sixCell, sevenCell, eightCell;
};