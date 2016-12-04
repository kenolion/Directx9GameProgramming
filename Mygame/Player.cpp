#include "Player.h"


Player::Player(float x, float y, float rotation, float speed, float maxSpeed) :GameObject(x, y, rotation, speed, maxSpeed)
{


}

void Player::update(int gameTime)
{

	if (status == ObjectStatus::Active) {
		for (int i = 0; i < gameTime; i++) {

			frame++;
			if (frame > maxFrame) {
				frame = 1;
			}


			position.z = 0;// not important

		}
	}
}


Player::~Player()
{
}
