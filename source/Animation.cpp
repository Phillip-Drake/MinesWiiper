#include "Animation.h"
Animation::Animation()
{
	totalImages = 0;
	currImage 	= 0;
	imgDelay = 0;
	isDone = true;
}

Animation::Animation(int totalImages)
{
	this->totalImages = totalImages;
	currImage = 1;
	imgDelay = 0;
}
Animation::Animation(int x, int y):Animation()
{
	currFrame.SetPosition(x, y);
}
Animation:: ~Animation()
{
}

bool Animation::HasNextFrame()
{
	if(totalImages > currImage)
		return true;
	return false;
}
void Animation::SetPosition(int x, int y)
{
	currFrame.SetPosition(x, y);
}



void Animation::PlayAnimation()
{

}