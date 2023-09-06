
#include "Animation.h"
#include "explosion00_png.h"
#include "explosion01_png.h"
#include "explosion02_png.h"
#include "explosion03_png.h"
#include "explosion04_png.h"
#include "explosion05_png.h"
#include "explosion06_png.h"
class Explosion : public Animation{
	public:
		Explosion();
		Explosion(int x, int y);
		~Explosion();
		void Draw();
		void LoadImage();
	private:
		Image img0, img1, img2, img3, img4, img5, img6;
};