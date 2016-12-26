#include "Platform.h"



void Platform::draw()
{
	GameObject::draw();
	collisionRect.top = position.y - 25;
	collisionRect.bottom = position.y + 5;
	collisionRect.left = position.x;
	collisionRect.right = position.x + spriteWidth;
}

void Platform::update(int &gameTime)
{
	
}


Platform::Platform(float x, float y, D3DXVECTOR2 scaling,int animSpeed) :GameObject(x, y, scaling,animSpeed)
{
	this->type = ObjectType::Platform;
}


Platform::~Platform()
{
}
