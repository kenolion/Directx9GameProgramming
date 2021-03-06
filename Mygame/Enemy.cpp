#include "Enemy.h"



Enemy::Enemy()
{
	type = ObjectType::Enemy;
}


Enemy::~Enemy()
{
}

Enemy::Enemy(float x, float y, D3DXVECTOR2 scaling, int animSpeed, float speed, int mass) :GameObject(x, y, scaling, animSpeed, speed, mass)
{

}

void Enemy::update(int &gameTime)
{
	for (int i = 0; i < gameTime; i++){
		position += velocity;
		if (position.x <= 0 - spriteWidth) {
			position.x = GAME_WIDTH;
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



