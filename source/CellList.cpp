#include "CellList.h"
#include <cstdio>
#include <iostream>
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
	unClickedCell.LoadImage(Garf_png, IMG_LOAD_TYPE_BUFFER);
	
}
CellList::~CellList() { }
void CellList::SpawnCells(int bombAmount)
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			cells[i][j].Spawn(i * 50 + 20, j * 50 + 20);
			cells[i][j].SetImage(unClickedCell);
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