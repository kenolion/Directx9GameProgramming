#include "Pictures.h"



Pictures::Pictures()
{
}


Pictures::Pictures(float x, float y, D3DXVECTOR2 scaling) : GameObject(x, y, scaling)
{

}

Pictures::~Pictures()
{
}

void Pictures::update(int &gameTime)
{
	for (int i = 0; i < gameTime; i++) {
		if (animTimer >= 60) {
			animTimer = 0;
			frame++;
			if (frame > maxFrame) {
				frame = maxFrame;
			}
		}
		animTimer += animSpeed;
	}
}
