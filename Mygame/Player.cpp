#include "Player.h"


Player::Player(float x, float y, D3DXVECTOR2 scaling, int animSpeed,float speed,int mass) :GameObject(x, y, scaling, animSpeed,speed,mass)
{
	this->type = ObjectType::Player;
	onGround = false;
}



void Player::update(int &gameTime)
{
	//std::cout << "X:" << position.x << "   " << std::endl;
	//std::cout << "Y:" << position.y << "   " << std::endl;
	//std::cout << "Velocity:" << velocity.x << "," << velocity.y << "   " << std::endl;
	
	if (status == ObjectStatus::Active) {

		for (int i = 0; i < gameTime; i++) {
			if (abs(velocity.x) < 0.3) {
				velocity.x = 0;
			}
			if (position.y > GAME_HEIGHT - spriteHeight) {
				velocity.y = 0;

			}
		
			if (onGround && !platformCollision) {
				velocity.y = 0;
			}
	
			if (!enemyCollision && !platformCollision || onGround) {
				this->position += velocity;

			}
			
			if (animTimer >=60) {
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


bool Player::getOnGroundStatus()
{
	return onGround;
}

void Player::setGroundStatus(bool status)
{
	onGround = status;
}

Player::~Player()
{
}
