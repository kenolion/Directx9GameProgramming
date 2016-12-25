#include "Player.h"


Player::Player(float x, float y, D3DXVECTOR2 scaling, int animSpeed,float speed,int mass) :GameObject(x, y, scaling, animSpeed,speed,mass)
{

	onGround = true;
}

void Player::update(int &gameTime)
{
	std::cout << "X:" << position.x << "   " << std::endl;
	std::cout << "Y:" << position.y << "   " << std::endl;
	std::cout << "Velocity:" << velocity.x << "," << velocity.y << "   " << std::endl;
	if (status == ObjectStatus::Active) {

		for (int i = 0; i < gameTime; i++) {
			if (abs(velocity.x) > PLAYERMAXVEL) {
				
				if(velocity.x < 0 )velocity.x = -PLAYERMAXVEL;
				else velocity.x = PLAYERMAXVEL;

			}
			//if (position.x > GAME_WIDTH - (spriteCentre.x * 2)) {
			//	velocity.x = -velocity.x;
			//}
			if (position.x < 0) {
				velocity.x +=5;
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
				this->position -= 5*velocity;
				velocity = { 0, 0 };
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

Player::~Player()
{
}
