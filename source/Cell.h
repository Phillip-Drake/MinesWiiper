#include <wiisprite.h>
#include <cstdlib>
#include "cursor_png.h"
#include "emptyCell_png.h"
#include "highlightedCell_png.h"
#include "flagCell_png.h"
#include "mine_png.h"
#include "zeroCell_png.h"
#include "oneCell_png.h"
#include "twoCell_png.h"
#include "threeCell_png.h"
#include "fourCell_png.h"
#include "fiveCell_png.h"
#include "sixCell_png.h"
#include "sevenCell_png.h"
#include "eightCell_png.h"
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
		void SetBasicImages(Image &unclickedImage, Image &highlightedImage, Image &flaggedImage);
		void SetClickedImage(Image &clickedImage);
	//Draws the cell
		void SetMine();
		void Draw();
		void IncrementNumMines();
		void Click();
		void Flag();
		void SetOver();
		void UnOver();
		int GetNumMines();
		bool IsMine();
		bool IsClicked();
		bool IsFlagged();
		int GetX();
		int GetY();
	//TODO : setMine() incrementNumMines() functions
	private : 
	//essential information for a cell, determines it's position,
	//number of mines nearby, if it is a mine, and some drawing garbage
		bool isMine, isClicked, isOver, isFlagged;
		int numMines;
		//POSSIBLY PASS IN x and y in the cellList.Draw() function??
		int x;
		int y;
		
		Sprite unclickedSprite, clickedSprite, highlightedSprite, flaggedSprite;
};