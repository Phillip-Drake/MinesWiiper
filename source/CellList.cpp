#include "CellList.h"
using namespace std;
CellList::CellList(){
//TODO : Implement Default constructor
}
CellList::CellList(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
	cells = new Cell*[rows];
	for(int i = 0; i < rows; i++)
			cells[i] = new Cell[columns];
	unClickedCell.LoadImage(one_png, IMG_LOAD_TYPE_BUFFER);
	mineCell.LoadImage(mine_png, IMG_LOAD_TYPE_BUFFER);
	oneCell.LoadImage(one_png, IMG_LOAD_TYPE_BUFFER);
	twoCell.LoadImage(two_png, IMG_LOAD_TYPE_BUFFER);
	threeCell.LoadImage(three_png, IMG_LOAD_TYPE_BUFFER);
	fourCell.LoadImage(four_png, IMG_LOAD_TYPE_BUFFER);
	fiveCell.LoadImage(five_png, IMG_LOAD_TYPE_BUFFER);
	sixCell.LoadImage(six_png, IMG_LOAD_TYPE_BUFFER);
	sevenCell.LoadImage(seven_png, IMG_LOAD_TYPE_BUFFER);
	eightCell.LoadImage(eight_png, IMG_LOAD_TYPE_BUFFER);
}
CellList::~CellList() { }
void CellList::SpawnCells(int bombAmount)
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			cells[i][j].Spawn(i * 20 + 20, j * 20 + 20);
		}
	}
	//seeds random
	srand(time(NULL));
	//generates bombAmount amount of bombs
	for(int i = 0; i < bombAmount; i++)
	{
		cells[std::rand() % rows][std::rand() % columns].SetMine();
	}
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			if(!cells[i][j].IsMine()){
				if(i == 0)
				{
					if(j == 0)
					{
						if(cells[i][j+1].IsMine())
							cells[i][j].IncrementNumMines();
						if(cells[i+1][j+1].IsMine())
							cells[i][j].IncrementNumMines();
						if(cells[i+1][j].IsMine())
							cells[i][j].IncrementNumMines();
					}
					else if(j == columns - 1)
					{
						if(cells[i][j-1].IsMine())
							cells[i][j].IncrementNumMines();
						if(cells[i+1][j-1].IsMine())
							cells[i][j].IncrementNumMines();
						if(cells[i+1][j].IsMine())
							cells[i][j].IncrementNumMines();
					}
					else
					{
						if(cells[i][j-1].IsMine())
							cells[i][j].IncrementNumMines();
						if(cells[i][j+1].IsMine())
							cells[i][j].IncrementNumMines();
						if(cells[i+1][j-1].IsMine())
							cells[i][j].IncrementNumMines();
						if(cells[i+1][j].IsMine())
							cells[i][j].IncrementNumMines();
						if(cells[i+1][j+1].IsMine())
							cells[i][j].IncrementNumMines();
						
					}
				}
				else if(i == rows - 1)
				{
					if(j == 0)
					{
						if(cells[i-1][j].IsMine())
							cells[i][j].IncrementNumMines();
						if(cells[i-1][j+1].IsMine())
							cells[i][j].IncrementNumMines();
						if(cells[i][j+1].IsMine())
							cells[i][j].IncrementNumMines();
					}
					else if(j == columns - 1)
					{
						if(cells[i-1][j-1].IsMine())
							cells[i][j].IncrementNumMines();
						if(cells[i-1][j].IsMine())
							cells[i][j].IncrementNumMines();
						if(cells[i][j-1].IsMine())
							cells[i][j].IncrementNumMines();
					}
					else
					{
						if(cells[i-1][j-1].IsMine())
							cells[i][j].IncrementNumMines();
						if(cells[i-1][j].IsMine())
							cells[i][j].IncrementNumMines();
						if(cells[i-1][j+1].IsMine())
							cells[i][j].IncrementNumMines();
						if(cells[i][j-1].IsMine())
							cells[i][j].IncrementNumMines();
						if(cells[i][j+1].IsMine())
							cells[i][j].IncrementNumMines();
					}
				}
				else
				{
					if(cells[i-1][j-1].IsMine())
							cells[i][j].IncrementNumMines();
					if(cells[i-1][j].IsMine())
							cells[i][j].IncrementNumMines();
					if(cells[i-1][j+1].IsMine())
							cells[i][j].IncrementNumMines();
					if(cells[i][j-1].IsMine())
							cells[i][j].IncrementNumMines();
					if(cells[i][j+1].IsMine())
							cells[i][j].IncrementNumMines();
					if(cells[i+1][j-1].IsMine())
							cells[i][j].IncrementNumMines();
					if(cells[i+1][j].IsMine())
							cells[i][j].IncrementNumMines();
					if(cells[i+1][j+1].IsMine())
							cells[i][j].IncrementNumMines();
				}
			}
			switch(cells[i][j].GetNumMines())
				{
					case 1:
						cells[i][j].SetImages(oneCell, mineCell);
						break;
					case 2:
						cells[i][j].SetImages(twoCell, mineCell);
						break;
					case 3:
						cells[i][j].SetImages(threeCell, mineCell);
						break;
					case 4:
						cells[i][j].SetImages(fourCell, mineCell);
						break;
					case 5:
						cells[i][j].SetImages(fiveCell, mineCell);
						break;
					case 6:
						cells[i][j].SetImages(sixCell, mineCell);
						break;
					case 7:
						cells[i][j].SetImages(sevenCell, mineCell);
						break;
					case 8:
						cells[i][j].SetImages(eightCell, mineCell);
						break;
					default:
						cells[i][j].SetImages(unClickedCell, mineCell);
						break;
				}
		}
	}
}
void CellList::ResetList()
{
	//TODO : Implement
}
void CellList::Draw()
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			cells[i][j].Draw();
		}
	}
}