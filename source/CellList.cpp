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
	loseExplosion = Explosion();
	hasLost = false;
}
//destructor
CellList::~CellList() 
{ 
	delete[] cells;
}

void CellList::SetSize(int rows, int columns, int minX, int minY, int maxX, int maxY)
{
	this->minX = minX;
	this->minY = minY;
	this->maxX = maxX;
	this->maxY = maxY;
	//prevents weird errors when resetting a cellList
	lastCell[0] = -1;
	//sets amount of rows and columns
	this->rows = rows;
	this->columns = columns;
	minRow = 0;
	minCol = 0;
	maxRow = rows;
	maxCol = columns;
	//initializes 2d array
	cells = new Cell*[rows];
	for(int i = 0; i < rows; i++)
			cells[i] = new Cell[columns];
	
}
//spawns each cell
void CellList::SpawnCells()
{
	// int xOffSet, yOffSet;
	// if(rows % 2 == 1)
		// xOffSet = 320 - (rows / 2) * 20;
	// else
		// xOffSet = (int)(320.0 - (rows / 2.0) * 20.0);
	// if(columns % 2 == 1)
		// yOffSet = 226 - (columns / 2) * 20;
	// else
		// yOffSet = (int)(260.0 - (columns / 2.0) * 20.0);
	//creates cells at the required x and y values
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			cells[i][j].Spawn(i *20 +  minX, j * 20 +  minY);
			cells[i][j].SetBasicImages(unClickedCell, highlightedCell, flaggedCell);
		}
	}
}

float CellList::GetInitialZoom()
{
	if(columns * 20.0 <= maxY)
		return 1;
	else
		return maxY / (columns * 20.0);
}
void CellList::AdjustCells(float zoomFactor, int xPan, int yPan)
{
	// int xOffSet, yOffSet;
	// if(rows % 2 == 1)
		// xOffSet = 320 - (rows / 2) * 20 * zoomFactor;
	// else
		// xOffSet = (int)(320.0 - (rows / 2.0) * 20.0 * zoomFactor);
	// if(columns % 2 == 1)
		// yOffSet = 226 - (columns / 2) * 20 * zoomFactor;
	// else
		// yOffSet = (int)(260.0 - (columns / 2.0) * 20.0 * zoomFactor);
	//creates cells at the required x and y values
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			cells[i][j].Spawn(i * 20 * zoomFactor +  minX + xPan, j * 20 * zoomFactor +  minY + yPan);
			//cells[i][j].Spawn(600, j * 20 * zoomFactor + yOffSet + yPan);
			cells[i][j].SetZoom(zoomFactor);
		}
	}
	//sets minimum rows seen on screen
	if(cells[0][0].GetX() < minX - 20)
	{
		minRow = (0 - cells[0][0].GetX()) / (20 * zoomFactor);
	}
	else
	{
		minRow = 0;
	}
	//sets maximum rows seen on screen
	if(cells[rows - 1][columns - 1].GetX() > maxX)
	{
		maxRow = ((maxX - cells[0][0].GetX()) / (20 * zoomFactor)) + 2;
		 if(maxRow > rows)
			 maxRow = rows;
	}
	//sets minimim and maximum columns seen on screen
	if(cells[0][0].GetY() < minY - 40)
	{
		minCol = (minY - 40 - cells[0][0].GetY()) / (20 * zoomFactor);
	}
	else
	{
		minCol = 0;
	}
	//sets maximum columns seen on screen
	if(cells[rows - 1][columns - 1].GetY() > maxY + 20)
	{
		maxCol = ((maxY + 20 - cells[0][0].GetY()) / (20 * zoomFactor)) + 2;
		 if(maxCol > columns)
			 maxCol = columns;
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
//checks if the cursor is over a cell
void CellList::OverCell(int x, int y, float zoomFactor)
{
	
	for(int i = minRow ; i < maxRow; i++)
	{
		for(int j = minCol; j < maxCol; j++)
		{
			
			if((cells[i][j].GetX() <= x && cells[i][j].GetX()+ (40 * zoomFactor) >= x) && (cells[i][j].GetY() <= y && cells[i][j].GetY()+ (40 * zoomFactor) >= y))
			{	
				if(lastCell[0] != -1)
					cells[lastCell[0]][lastCell[1]].UnOver();
				cells[i][j].SetOver();
				lastCell[0] = i;
				lastCell[1] = j;
			}
		}
	}
}
//clicks the last cell that the mouse was over
void CellList::ClickLastCell()
{
	if(lastCell[0] != -1 && !cells[lastCell[0]][lastCell[1]].IsFlagged())
	{
		//recursive clicking for all nearby cells if there are no nearby mines
		if(cells[lastCell[0]][lastCell[1]].GetNumMines() == 0 && !cells[lastCell[0]][lastCell[1]].IsMine() && !cells[lastCell[0]][lastCell[1]].IsFlagged())
		{
			RecursiveClick(lastCell[0], lastCell[1]);
		}
		cells[lastCell[0]][lastCell[1]].Click();
	}
}
void CellList::FlagLastCell()
{
	if(lastCell[0] != -1 && !cells[lastCell[0]][lastCell[1]].IsClicked())
	{
		cells[lastCell[0]][lastCell[1]].Flag();
	}
}
//clicks the cell which the cursor is on
//IF the cell contains 0 mines, clicks every cell around that cell IF the cell hasn't already been clicket yet
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
}
//win condition
//return 1 if Win, return 2 if Lose, else return 0
int CellList::CheckWinLose()
{
	int cellsRemaining = 0, minesRemaining = 0;
	if(lastCell[0] != -1 && cells[lastCell[0]][lastCell[1]].IsMine())
	{
		Lose();
		hasLost = true;
		return 0;
	}
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			if(!cells[i][j].IsClicked())
			{
				if(cells[i][j].IsMine())
					minesRemaining++;
				cellsRemaining++;
			}
			
		}
	}
	if(cellsRemaining == minesRemaining)
		return 1;
	return 0;
}
void CellList::Lose()
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			if(!cells[i][j].IsClicked() && cells[i][j].IsMine())
				cells[i][j].Click();
		}
	}
	loseExplosion.SetPosition(cells[lastCell[0]][lastCell[1]].GetX() - 44 + 10 * cells[lastCell[0]][lastCell[1]].GetZoom(), cells[lastCell[0]][lastCell[1]].GetY() - 48 + 10 * cells[lastCell[0]][lastCell[1]].GetZoom());
}
void CellList::Draw()
{
	for(int i = minRow; i < maxRow; i++)
	{
		for(int j = minCol; j < maxCol; j++)
		{
			cells[i][j].Draw();
		}
	}
	if(hasLost)
		loseExplosion.Draw();
}