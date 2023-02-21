#include "MineCounter.h"

MineCounter::MineCounter()
{
	amount = 0;
}

MineCounter::MineCounter(int x, int y, int min, int max)
{
	this-> x = x;
	this-> y = y;
	this-> amount = min;
	this-> min = min;
	this-> max = max;
}
void MineCounter::Spawn(int x, int y, int min, int max)
{
	this->x = x;
	this->y = y;
	this->amount = min;
	this-> min = min;
	this-> max = max;
}
void MineCounter::SetImages(Image &num0, Image &num1, Image &num2, Image &num3, Image &num4, Image &num5, Image &num6, Image &num7, Image &num8, Image &num9)
{
	sprites[0].SetImage(&num0);
	sprites[1].SetImage(&num1);
	sprites[2].SetImage(&num2);
	sprites[3].SetImage(&num3);
	sprites[4].SetImage(&num4);
	sprites[5].SetImage(&num5);
	sprites[6].SetImage(&num6);
	sprites[7].SetImage(&num7);
	sprites[8].SetImage(&num8);
	sprites[9].SetImage(&num9);
}

void MineCounter::IncrementAmount()
{
	if(amount >= max)
		amount = min;
	else
		amount++;
}

void MineCounter::DecrementAmount()
{
	if(amount <= min)
		amount = max;
	else
		amount--;
}

int MineCounter::GetAmount()
{
	return amount;
}

void MineCounter::Draw()
{
	//draws the 10s place digits with position x, y
	sprites[amount / 10].SetPosition(x, y);
	sprites[amount / 10].Draw();
	//sets the position of the 1s place digit to that of position x + 10sdigitwidth, y
	sprites[amount % 10].SetPosition(x + sprites[amount/10].GetCollisionRectangle()->width, y);
	//draws the 1s place digit
	sprites[amount % 10].Draw();
}
