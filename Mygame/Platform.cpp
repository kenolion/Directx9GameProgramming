#include "Platform.h"


Platform::Platform(float x, float y, D3DXVECTOR2 scaling, int animSpeed):GameObject(x,y,scaling,animSpeed)
{
}


void Platform::update(int &gameTime) {

	playerCheck.top = position.y - 5;
	playerCheck.left = position.x;
	playerCheck.right = position.x + spriteRect.right;
	playerCheck.bottom = position.y + 30;

}

void Platform::draw()
{
	GameObject::draw();



}

Platform::~Platform()
{
}
