#include "Cell.h"
using namespace wsp;

//Initializes important values
Cell::Cell() {
	isOver = false;
	isClicked = false;
	isMine = false;
	isFlagged = false;
	numMines = 0;
}
//does initializations, then spawns the cell
Cell::Cell(int x, int y){
	Cell();
	Spawn(x, y);
}

Cell::~Cell() {}
//sets the x and y values of the cell, sets those values to any sprites in the cell aswell
void Cell::Spawn(int x, int y){
	this->x = x;
	this->y = y;
	unclickedSprite.SetPosition(x, y);
	highlightedSprite.SetPosition(x, y);
	clickedSprite.SetPosition(x, y);
	flaggedSprite.SetPosition(x, y);
}


//sets the images of the cell, passes in references to images in another function, so they don't need to be held in multiple places
void Cell::SetBasicImages(Image &unclickedImage, Image &highlightedImage, Image &flaggedImage)
{
	unclickedSprite.SetImage(&unclickedImage);
	highlightedSprite.SetImage(&highlightedImage);
	flaggedSprite.SetImage(&flaggedImage);
}
//sets image with number on it, this is done seperately from basic images in order to allow the game to be displayed without any bombs being placed
void Cell::SetClickedImage(Image &clickedImage)
{
	clickedSprite.SetImage(&clickedImage);
}
//clicks the cell
void Cell::Click()
{
	isClicked = true;
}

void Cell::Flag()
{
	isFlagged = !isFlagged;
}
//sets the cell as a mine
void Cell::SetMine(){
	isMine = true;
}

void Cell::SetZoom()
{
	unclickedSprite.SetZoom(zoomFactor);
	highlightedSprite.SetZoom(zoomFactor);
	clickedSprite.SetZoom(zoomFactor);
	flaggedSprite.SetZoom(zoomFactor);
	
}
//increases the amount of mines next to the cell by one
//my program iteratively increases the amount of mines next to the cell through many checks, so the value cannot be directly assigned
void Cell::IncrementNumMines()
{
	numMines++ ;
}
//returns the number of mines nearby the cell
int Cell::GetNumMines()
{
	return numMines;
}
//returns whether the cell is a mine
bool Cell::IsMine()
{
	return isMine;
}

bool Cell::IsClicked()
{
	return isClicked;
}
bool Cell::IsFlagged()
{
	return isFlagged;
}
//returns the cell's x value
int Cell::GetX()
{
	return x;
}
//returns the cell's y value
int Cell::GetY()
{
	return y;
}
//sets the cell as being hovered over by the cursor
void Cell::SetOver()
{
	isOver = true;
}
//sets the cell as no longer being hovered over by the cursor
void Cell::UnOver()
{
	isOver = false;
}
//draws the cell
void Cell::Draw(){
	if(!isClicked)
	{
		if(isFlagged)
			flaggedSprite.Draw();
		else if(isOver)
			highlightedSprite.Draw();
		else
			unclickedSprite.Draw();
	}
	else
	{
		clickedSprite.Draw();
	}
}