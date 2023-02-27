#include "MainScreen.h"

MainScreen::MainScreen()
{
	mineAmount = 0;
	//counter image initialization
	zero.LoadImage(zero_png, IMG_LOAD_TYPE_BUFFER);
	one.LoadImage(one_png, IMG_LOAD_TYPE_BUFFER);
	two.LoadImage(two_png, IMG_LOAD_TYPE_BUFFER);
	three.LoadImage(three_png, IMG_LOAD_TYPE_BUFFER);
	four.LoadImage(four_png, IMG_LOAD_TYPE_BUFFER);
	five.LoadImage(five_png, IMG_LOAD_TYPE_BUFFER);
	six.LoadImage(six_png, IMG_LOAD_TYPE_BUFFER);
	seven.LoadImage(seven_png, IMG_LOAD_TYPE_BUFFER);
	eight.LoadImage(eight_png, IMG_LOAD_TYPE_BUFFER);
	nine.LoadImage(nine_png, IMG_LOAD_TYPE_BUFFER);
	//set counter images
	heightCounter.SetImages(zero, one, two, three, four, five, six, seven, eight, nine);
	widthCounter.SetImages(zero, one, two, three, four, five, six, seven, eight, nine);
	//spawn counters
	heightCounter.Spawn(256, 64, 4, 99);
	widthCounter.Spawn(256, 160, 4, 99);
	//load arrow Images
	leftArrow.LoadImage(leftArrow_png, IMG_LOAD_TYPE_BUFFER);
	leftArrowHighlighted.LoadImage(leftArrowHighlighted_png, IMG_LOAD_TYPE_BUFFER);
	rightArrow.LoadImage(rightArrow_png, IMG_LOAD_TYPE_BUFFER);
	rightArrowHighlighted.LoadImage(rightArrowHighlighted_png, IMG_LOAD_TYPE_BUFFER);
	//arrow image initialization
	widthLeftArrow.SetImages(leftArrow, leftArrowHighlighted);
	heightLeftArrow.SetImages(leftArrow, leftArrowHighlighted);
	widthRightArrow.SetImages(rightArrow, rightArrowHighlighted);
	heightRightArrow.SetImages(rightArrow, rightArrowHighlighted);
	//arrow spawning
	heightLeftArrow.Spawn(192, 64);
	widthLeftArrow.Spawn(192, 160);
	heightRightArrow.Spawn(384, 64);
	widthRightArrow.Spawn(384, 160);
	//mine button image initialization
	mineAmountOne.LoadImage(mineAmountOne_png, IMG_LOAD_TYPE_BUFFER);
	mineAmountOneHighlighted.LoadImage(mineAmountOneHighlighted_png, IMG_LOAD_TYPE_BUFFER);
	mineAmountTwo.LoadImage(mineAmountTwo_png, IMG_LOAD_TYPE_BUFFER);
	mineAmountTwoHighlighted.LoadImage(mineAmountTwoHighlighted_png, IMG_LOAD_TYPE_BUFFER);
	mineAmountThree.LoadImage(mineAmountThree_png, IMG_LOAD_TYPE_BUFFER);
	mineAmountThreeHighlighted.LoadImage(mineAmountThreeHighlighted_png, IMG_LOAD_TYPE_BUFFER);
	//mine button initialization
	mineNormal.SetImages(mineAmountOne, mineAmountOneHighlighted);
	mineALot.SetImages(mineAmountTwo, mineAmountTwoHighlighted);
	mineTooMany.SetImages(mineAmountThree, mineAmountThreeHighlighted);
	//mine button spawning
	mineNormal.Spawn(96, 272);
	mineALot.Spawn(256, 272);
	mineTooMany.Spawn(416, 272);
	//start button image initialization
	start.LoadImage(start_png, IMG_LOAD_TYPE_BUFFER);
	startHighlighted.LoadImage(startHighlighted_png, IMG_LOAD_TYPE_BUFFER);
	//load start button images
	startButton.SetImages(start, startHighlighted);
	//start button spawning
	startButton.Spawn(256, 368);
	//load label images
	widthImage.LoadImage(widthLabel_png, IMG_LOAD_TYPE_BUFFER);
	heightImage.LoadImage(heightLabel_png, IMG_LOAD_TYPE_BUFFER);
	minesImage.LoadImage(minesLabel_png, IMG_LOAD_TYPE_BUFFER);
	//label sprite initialization
	widthSprite.SetImage(&widthImage);
	heightSprite.SetImage(&heightImage);
	minesSprite.SetImage(&minesImage);
	heightSprite.SetPosition(256, 32);
	widthSprite.SetPosition(256, 128);
	minesSprite.SetPosition(256, 224);
}

int MainScreen::GetHeight()
{
	return heightCounter.GetAmount();
}
int MainScreen::GetWidth()
{
	return widthCounter.GetAmount();
}
int MainScreen::GetMines()
{
	return mineAmount;
}
bool MainScreen::Click()
{
	if(heightLeftArrow.Click())
		heightCounter.DecrementAmount();
	else if(widthLeftArrow.Click())
		widthCounter.DecrementAmount();
	else if(heightRightArrow.Click())
		heightCounter.IncrementAmount();
	else if(widthRightArrow.Click())
		widthCounter.IncrementAmount();
	else if(mineNormal.Click())
		mineAmount = 1;
	else if(mineALot.Click())
		mineAmount = 2;
	else if(mineTooMany.Click())
		mineAmount = 8;
	else if(startButton.Click())
		return true;
	
	return false;
}
void MainScreen::Update(int x, int y)
{
	heightLeftArrow.IsOver(x, y);
	widthLeftArrow.IsOver(x, y);
	mineLeftArrow.IsOver(x, y);
	heightRightArrow.IsOver(x, y);
	widthRightArrow.IsOver(x, y);
	mineRightArrow.IsOver(x, y);
	startButton.IsOver(x, y);
	mineNormal.IsOver(x, y);
	mineALot.IsOver(x, y);
	mineTooMany.IsOver(x, y);
	Draw();
}
void MainScreen::Draw()
{
	//counter drawing
	mineCounter.Draw();
	heightCounter.Draw();
	widthCounter.Draw();
	//arrow drawing
	heightLeftArrow.Draw();
	widthLeftArrow.Draw();
	mineLeftArrow.Draw();
	heightRightArrow.Draw();
	widthRightArrow.Draw();
	mineRightArrow.Draw();
	//mine button drawing
	mineNormal.Draw();
	mineALot.Draw();
	mineTooMany.Draw();
	//start button drawing
	startButton.Draw();
	//label drawing
	heightSprite.Draw();
	widthSprite.Draw();
	minesSprite.Draw();
}