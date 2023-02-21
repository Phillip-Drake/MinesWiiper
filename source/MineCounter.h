#include <wiisprite.h>
#include <cstdlib>

using namespace wsp;
class MineCounter { 
	public : 
		MineCounter();
		MineCounter(int x, int y, int amount);
		void Spawn(int x, int y, int amount);
		void SetImages(Image &num0, Image &num1, Image &num2, Image &num3, Image &num4, Image &num5, Image &num6, Image &num7, Image &num8, Image &num9);
		void IncrementAmount();
		void DecrementAmount();
		int GetAmount();
		void Draw();
	private : 
		Sprite sprites[10]; 

		int x, y, amount;
};