#include "CellList.h"
CellList::CellList()
{
	unClickedCell.LoadImage(emptyCell_png, IMG_LOAD_TYPE_BUFFER);
	highlightedCell.LoadImage(highlightedCell_png, IMG_LOAD_TYPE_BUFFER);
	mineCell.LoadImage(mine_png, IMG_LOAD_TYPE_BUFFER);
	flaggedCell.LoadImage(flagCell_png, IMG_LOAD_TYPE_BUFFER);
	zeroCell.LoadImage(zeroCell_png, IMG_LOAD_TYPE_BUFFER);
	oneCell.LoadImage(oneCell_png, IMG_LOAD_TYPE_BUFFER);
	twoCell.LoadImage(twoCell_png, IMG_LOAD_TYPE_BUFFER);
	threeCell.LoadImage(threeCell_png, IMG_LOAD_TYPE_BUFFER);
	fourCell.LoadImage(fourCell_png, IMG_LOAD_TYPE_BUFFER);
	fiveCell.LoadImage(fiveCell_png, IMG_LOAD_TYPE_BUFFER);
	sixCell.LoadImage(sixCell_png, IMG_LOAD_TYPE_BUFFER);
	sevenCell.LoadImage(sevenCell_png, IMG_LOAD_TYPE_BUFFER);
	eightCell.LoadImage(eightCell_png, IMG_LOAD_TYPE_BUFFER);
}
//destructor
CellList::~CellList() { }

void CellList::SetSize(int rows, int columns)
{
	//sets amount of rows and columns
	this->rows = rows;
	this->columns = columns;
	//initializes 2d array
	cells = new Cell*[rows];
	for(int i = 0; i < rows; i++)
			cells[i] = new Cell[columns];
}
//spawns each cell
void CellList::SpawnCells()
{
	int xOffSet, yOffSet;
	if(rows % 2 == 1)
		xOffSet = 320 - (rows / 2) * 20;
	else
		xOffSet = (int)(320.0 - (rows / 2.0) * 20.0);
	if(columns % 2 == 1)
		yOffSet = 226 - (columns / 2) * 20;
	else
		yOffSet = (int)(260.0 - (columns / 2.0) * 20.0);
	//creates cells at the required x and y values
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			cells[i][j].Spawn(i *20 +  xOffSet, j * 20 +  yOffSet);
			cells[i][j].SetBasicImages(unClickedCell, highlightedCell, flaggedCell);
		}
	}
}

float CellList::GetInitialZoom()
{
	if(columns * 20.0 <= 480.0)
		return 1;
	else
		return 480.0 / (columns * 20.0);
}
void CellList::AdjustCells(float zoomFactor, int xPan, int yPan)
{
	int xOffSet, yOffSet;
	if(rows % 2 == 1)
		xOffSet = 320 - (rows / 2) * 20 * zoomFactor;
	else
		xOffSet = (int)(320.0 - (rows / 2.0) * 20.0 * zoomFactor);
	if(columns % 2 == 1)
		yOffSet = 226 - (columns / 2) * 20 * zoomFactor;
	else
		yOffSet = (int)(260.0 - (columns / 2.0) * 20.0 * zoomFactor);
	//creates cells at the required x and y values
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			cells[i][j].Spawn(i * 20 * zoomFactor +  xOffSet + xPan, j * 20 * zoomFactor +  yOffSet + yPan);
			cells[i][j].SetZoom(zoomFactor);
		}
	}
}
//spawns the bombs onto the list
void CellList::SpawnBombs(int bombAmount)
{
	//seeds random
	srand(time(NULL));
	//generates bombAmount amount of bombs
	int randRow, randCol;
	for(int i = 0; i < bombAmount; i++)
	{
		randRow = std::rand() % rows;
		randCol = std::rand() % columns;
		//requires that the bombs not be placed on / next to the cell which the cursor clicked
		while((randRow >= lastCell[0] - 1 && randRow <= lastCell[0] + 1) && (randCol >= lastCell[1] - 1 && randCol <= lastCell[1] + 1))
		{
			randRow = std::rand() % rows;
			randCol = std::rand() % columns;
		}
		cells[randRow][randCol].SetMine();
	}
	int currRow, currCol;
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			if(cells[i][j].IsMine())
			{
				//re-reformed numbering system
				for(int k = -1; k < 2; k++)
				{
					for(int g = -1; g < 2; g++)
					{
						currRow = i + k;
						currCol = j + g;
						if((currRow >= 0 && currRow < rows) && (currCol >= 0 && currCol < columns))
							cells[currRow][currCol].IncrementNumMines();
					}
				}
			}
		}
	}
	//requires second loop in order to set cell-images
	//TODO : Add possibly set images at draw? I'm not actually sure if that would be faster
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			if(cells[i][j].IsMine())
			{
				cells[i][j].SetClickedImage(mineCell);
			}
			else
			{
				switch(cells[i][j].GetNumMines())
					{
						case 1:
							cells[i][j].SetClickedImage(oneCell);
							break;
						case 2:
							cells[i][j].SetClickedImage(twoCell);
							break;
						case 3:
							cells[i][j].SetClickedImage(threeCell);
							break;
						case 4:
							cells[i][j].SetClickedImage(fourCell);
							break;
						case 5:
							cells[i][j].SetClickedImage(fiveCell);
							break;
						case 6:
							cells[i][j].SetClickedImage(sixCell);
							break;
						case 7:
							cells[i][j].SetClickedImage(sevenCell);
							break;
						case 8:
							cells[i][j].SetClickedImage(eightCell);
							break;
						default:
							cells[i][j].SetClickedImage(zeroCell);
							break;
					}
			}
		}
	}
}
void CellList::ResetList()
{
	//TODO : Implement
}

//checks if the cursor is over a cell
void CellList::OverCell(int x, int y)
{
	
	for(int i = 0 ; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			
			if((cells[i][j].GetX() <= x && cells[i][j].GetX()+40 >= x) && (cells[i][j].GetY() <= y && cells[i][j].GetY()+40 >= y))
			{	
				cells[lastCell[0]][lastCell[1]].UnOver();
				cells[i][j].SetOver();
				lastCell[0] = i;
				lastCell[1] = j;
			}
		}
	}
	
}

void CellList::ClickLastCell()
{
	//recursive clicking for all nearby cells if there are no nearby mines
	if(!cells[lastCell[0]][lastCell[1]].IsFlagged())
	{
		if(cells[lastCell[0]][lastCell[1]].GetNumMines() == 0 && !cells[lastCell[0]][lastCell[1]].IsMine() && !cells[lastCell[0]][lastCell[1]].IsFlagged())
		{
			RecursiveClick(lastCell[0], lastCell[1]);
		}
		cells[lastCell[0]][lastCell[1]].Click();
	}
}

void CellList::FlagLastCell()
{
	if(!cells[lastCell[0]][lastCell[1]].IsClicked())
	{
		cells[lastCell[0]][lastCell[1]].Flag();
	}
}
void CellList::RecursiveClick(int row, int col)
{
	int currRow, currCol;
	cells[row][col].Click();
	if(cells[row][col].GetNumMines() == 0)
	{
		for(int i = -1; i < 2; i++)
		{
			for(int j = -1; j < 2; j++)
			{
				currRow = row + i;
				currCol = col + j;
				if((currRow >=0 && currRow < rows) && (currCol >= 0 && currCol < columns))
				{
					if(!cells[currRow][currCol].IsClicked() && !cells[currRow][currCol].IsFlagged())
					{
						RecursiveClick(currRow, currCol);
					}
				}				
			}
		}
	}
	// if((row >= 0 && row < rows) && (col >= 0 && col < columns))
	// {
		// if(cells[row][col].GetNumMines() == 0 && !cells[row][col].IsMine() && !cells[row][col].IsClicked())
		// {
			// if(!cells[lastCell[0]][lastCell[1]].IsFlagged())
				// cells[row][col].Click();
			// RecursiveClick(row-1, col-1);
			// RecursiveClick(row-1, col);
			// RecursiveClick(row-1, col+1);
			// RecursiveClick(row, col-1);
			// RecursiveClick(row, col);
			// RecursiveClick(row, col+1);
			// RecursiveClick(row+1, col-1);
			// RecursiveClick(row+1, col);
			// RecursiveClick(row+1, col+1);
		// }
		// else if(!cells[row][col].IsMine())
			// cells[row][col].Click();
	// }
	
}
void CellList::Draw()
{
	for(int i; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			cells[i][j].Draw();
		}
	}
}