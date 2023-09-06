#include <wiisprite.h>
#include <cstdlib>
using namespace wsp;
class Animation
{
	public:
		Animation();
		Animation(int totalImages);
		Animation(int x, int y);
		~Animation();
		void PlayAnimation();
		bool HasNextFrame();
		virtual void Draw() = 0;
		virtual void LoadImage() = 0;
		void SetPosition(int x, int y);
	protected:
		int totalImages, currImage, imgDelay;
		bool isDone;
		Sprite currFrame;
		
};