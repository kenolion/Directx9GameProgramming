#include "Player.h"


Player::Player(float x, float y, float rotation) :GameObject(x, y,rotation)
{


}

void Player::update(int gameTime,bool keyPressed)
{

	if (status == ObjectStatus::Active) {
		
		for (int i = 0; i < gameTime; i++) {
			
			
			if (!collision && keyPressed) {
				std::cout << acceleration.x << std::endl;
				std::cout << position.x << std::endl;
				std::cout << velocity.x;
				D3DXVec3Add(&velocity, &velocity, &acceleration);
				D3DXVec3Add(&position, &position, &velocity);
				velocity.x *= 0.7;		// friction
				velocity.y *= 0.7;
				acceleration.x *= 0.5;
				acceleration.y *= 0.5;
			}
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
