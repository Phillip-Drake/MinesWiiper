#include "Button.h"
Button::Button()
{
	isOver = false;
	isClicked = false;
}
Button::Button(int x, int y)
{
	Button();
	this->x = x;
	this->y = y;
}
Button::~Button(){ }

void Button::Spawn(int x, int y)
{
	this->x = x;
	this->y = y;
	sprite.SetPosition(x, y);
	overSprite.SetPosition(x, y);
}
//sets images for the button to use
void Button::SetImages(Image &image, Image &overImage)
{
	sprite.SetImage(&image);
	overSprite.SetImage(&overImage);
}
//checks if the cursor is over the button
void Button::IsOver(int x, int y)
{
	int width = sprite.GetCollisionRectangle()->width;
	int height = sprite.GetCollisionRectangle()->height;
	if((x >= this-> x && x <= this->x + width) && (y >= this-> y && y <= this->y + height))
		isOver = true;
	else
		isOver = false;
}
//checks if the cursor is over the button, if so, returns click to main
bool Button::Click()
{
	if(isOver)
		return true;
	else
		return false;
}
//draws either the sprite, or the over sprite
void Button::Draw()
{
	if(isOver)
		overSprite.Draw();
	else
		sprite.Draw();
}