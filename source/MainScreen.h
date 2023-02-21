#include "Button.h"
#include "MineCounter.h"
#include "zero_png.h"
#include "one_png.h"
#include "two_png.h"
#include "three_png.h"
#include "four_png.h"
#include "five_png.h"
#include "six_png.h"
#include "seven_png.h"
#include "eight_png.h"
#include "nine_png.h"
#include "leftArrow_png.h"
#include "rightArrow_png.h"
#include "leftArrowHighlighted_png.h"
#include "rightArrowHighlighted_png.h"
#include "start_png.h"
#include "startHighlighted_png.h"
//Main Homescreen
class MainScreen {
	public : 
		MainScreen();
		bool Click();
		void Update(int x, int y);
		void Draw();
		int GetHeight();
		int GetWidth();
		int GetMines();
	private : 
		Button mineLeftArrow, mineRightArrow, widthLeftArrow, widthRightArrow, heightLeftArrow, heightRightArrow;
		Button startButton;
		MineCounter heightCounter, widthCounter, mineCounter;
		Image zero, one, two, three, four, five, six, seven, eight, nine;
		Image leftArrow, leftArrowHighlighted, rightArrow, rightArrowHighlighted;
		Image start, startHighlighted;
};