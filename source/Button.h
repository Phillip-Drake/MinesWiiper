#include <wiisprite.h>
#include <cstdlib>
using namespace wsp;
//framework for any button I make
//Button Examples : Right and left arrows to decide amount of cells, start game, reset board, etc
class Button {
	public : 
		Button();
		Button(int x, int y);
		~Button();
		void Spawn(int x, int y);
		void SetImages(Image &image, Image &overImage);
		void IsOver(int x, int y);
		bool Click();
		void Draw();
	private : 
	//essential information for a button object
		int x, y;
		bool isOver, isClicked;
		Sprite sprite, overSprite;
		

};