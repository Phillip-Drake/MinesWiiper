#include <wiisprite.h>
#include "Garf_png.h"
using namespace wsp;

class Cell {
	public : 
	//default constructor, constructor with basic parameters
		Cell();
		Cell(int x, int y);
		~Cell();
	//spawns the cell
		void Spawn(int x, int y);
	//sets the image of the sprite
		void SetImage(Image &image);
	//Draws the cell
		void Draw();
	//TODO : setMine() incrementNumMines() functions
	private : 
	//essential information for a cell, determines it's position,
	//number of mines nearby, if it is a mine, and some drawing garbage
		bool isMine;
		int numMines;
		//POSSIBLY PASS IN x and y in the cellList.Draw() function??
		int x;
		int y;
		
		Sprite sprite;
};