#include "Cell.h"
using namespace wsp;
class CellList{

	public :
		CellList();
		CellList(int rows, int columns); 
		~CellList();
		void SpawnCells();
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