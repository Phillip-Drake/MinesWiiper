#include "Cell.h"
using namespace wsp;

Cell::Cell() {
}

Cell::Cell(int x, int y){
	Cell();
	Spawn(x, y);
}

Cell::~Cell() {}

void Cell::Spawn(int x, int y){
	this->x = x;
	this->y = y;
	sprite.SetPosition(x, y);
}

void Cell::SetImage(Image &image){
	sprite.SetImage(&image);
}

void Cell::Draw(){
	sprite.Draw();
}