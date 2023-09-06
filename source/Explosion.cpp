
#include "Explosion.h"
Explosion::Explosion():Animation()
{
	totalImages = 6;
	LoadImage();
}
Explosion::Explosion(int x, int y):Animation(x, y)
{
	totalImages = 6;
	LoadImage();
}
Explosion::~Explosion()
{
		
}
void Explosion::Draw()
{
	
	if(imgDelay == 6)
	{
		switch(currImage)
		{
			case 0:
				currFrame.SetImage(&img0);
				break;
			case 1:
				currFrame.SetImage(&img1);
				break;
			case 2:
				currFrame.SetImage(&img2);
				break;
			case 3:
				currFrame.SetImage(&img3);
				break;
			case 4:
				currFrame.SetImage(&img4);
				break;
			case 5:
				currFrame.SetImage(&img5);
				break;
			case 6:
				currFrame.SetImage(&img6);
				break;
			default:
				break;
		}
		
		currImage++;
		imgDelay = 0;
	}
	else
		imgDelay++;
	currFrame.Draw();
	if(currImage > totalImages)
		currImage = 0;
	
}
void Explosion::LoadImage()
{
	img0.LoadImage(explosion00_png, IMG_LOAD_TYPE_BUFFER);
	img1.LoadImage(explosion01_png, IMG_LOAD_TYPE_BUFFER);
	img2.LoadImage(explosion02_png, IMG_LOAD_TYPE_BUFFER);
	img3.LoadImage(explosion03_png, IMG_LOAD_TYPE_BUFFER);
	img4.LoadImage(explosion04_png, IMG_LOAD_TYPE_BUFFER);
	img5.LoadImage(explosion05_png, IMG_LOAD_TYPE_BUFFER);
	img6.LoadImage(explosion06_png, IMG_LOAD_TYPE_BUFFER);
	
}

