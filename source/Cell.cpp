#include "Cell.h"
using namespace wsp;

Cell::Cell() {
	isMine = false;
	numMines = 0;
}

Cell::Cell(int x, int y){
	Cell();
	Spawn(x, y);
}

Cell::~Cell() {}

void Cell::Spawn(int x, int y){
	this->x = x;
	this->y = y;
	unclickedSprite.SetPosition(x, y);
	mineSprite.SetPosition(x, y);
}

void Cell::SetImages(Image &unclickedImage, Image &mineImage){
	unclickedSprite.SetImage(&unclickedImage);
	mineSprite.SetImage(&mineImage);
}

void Cell::SetMine(){
	isMine = true;
}

void Cell::IncrementNumMines()
{
	numMines = 3;
}
int Cell::GetNumMines()
{
	return numMines;
}
bool Cell::IsMine()
{
	return isMine;
}
void Cell::Draw(){
	if(isMine)
		mineSprite.Draw();
	else
		unclickedSprite.Draw();
}