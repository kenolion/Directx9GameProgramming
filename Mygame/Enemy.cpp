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
	if (status == ObjectStatus::Dead) {

		for (int i = 0; i < gameTime; i++) {
			if (abs(velocity.x) > PLAYERMAXVEL) {

				if (velocity.x < 0)velocity.x = -PLAYERMAXVEL;
				else velocity.x = PLAYERMAXVEL;

			}
			//if (position.x > GAME_WIDTH - (spriteCentre.x * 2)) {
			//	velocity.x = -velocity.x;
			//}
			if (position.x < 0) {
				velocity.x += 5;
			}
			if (position.y >GROUND_LEVEL) {
				velocity.y = 0;
			}
			//else if (position.y < 0) {
			//	velocity.y = -velocity.y;
			//}

			if (!collision) {
				this->position += velocity;

			}
			else {
				this->position -= 5 * velocity;
				velocity = { 0, 0 };
			}
			if (animTimer >= 60) {
				animTimer = 0;
				frame++;
				if (frame > maxFrame) {
					frame = 1;
				}
			}
			animTimer += animSpeed;

		}
	}
}
