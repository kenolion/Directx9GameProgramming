#include "Enemy.h"



Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

Enemy::Enemy(float x, float y, D3DXVECTOR2 scaling, int animSpeed, float speed, int mass) :GameObject(x, y, scaling, animSpeed, speed, mass)
{

}

void Enemy::update(int &gameTime)
{
	std::cout << "Enemy X:" << position.x << "   " << std::endl;
	std::cout << "Enemy Y:" << position.y << "   " << std::endl;
	std::cout << "Enemy Velocity:" << velocity.x << "," << velocity.y << "   " << std::endl;

	this->position = position;

	if (position.x < -50)
	{
		position.x = GAME_WIDTH;
		//ObjectStatus::Dead;
	}

	if (status == ObjectStatus::Dead) {

	}
	
	velocity.x = -1;					//The goomba just walks left, lel.
	this->position += velocity;

			if (animTimer >= 60) {
				animTimer = 0;
				frame++;
				if (frame > maxFrame) {
					frame = 1;
				}
			}
			animTimer += animSpeed;
}

void Enemy::draw()
{
	GameObject::draw();
	goombaHitBox.top = position.x;// Top Right
	goombaHitBox.bottom = position.x + spriteHeight;// Bottom Right?
	goombaHitBox.left = position.x;			//
	goombaHitBox.right = position.y + spriteWidth;

	 hitBoxTop = goombaHitBox.top;
	 hitBoxBottom = goombaHitBox.bottom;
	 hitBoxLeft = goombaHitBox.left;
	 hitBoxRight =goombaHitBox.right;

}

