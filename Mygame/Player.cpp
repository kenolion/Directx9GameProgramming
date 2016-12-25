#include "Player.h"


Player::Player(float x, float y, float rotation, D3DXVECTOR2 scaling, float enginePower, int mass) :GameObject(x, y, rotation, scaling, enginePower, mass)
{


}

void Player::update(int &gameTime, D3DXVECTOR2 &position, D3DXVECTOR2 &force)
{
	std::cout << "X:" << position.x << "   " << std::endl;
	std::cout << "Y:" << position.y << "   " << std::endl;
	std::cout << "Velocity:" << velocity.x << "," << velocity.y << "   " << std::endl;
	this->position = position;
	if (status == ObjectStatus::Dead) {

		for (int i = 0; i < gameTime; i++) {

			if (position.x > GAME_WIDTH - (spriteCentre.x * 2)) {
				velocity.x = -velocity.x;
			}
			else if (position.x < 0) {
				velocity.x = -velocity.x;
			}
			else if (position.y > GAME_HEIGHT - (spriteCentre.x * 2)) {
				velocity.y = -velocity.y;
			}
			else if (position.y < 0) {
				velocity.y = -velocity.y;
			}

			if (!collision) {
				this->position += velocity;

			}
			else {
				this->position -= velocity;
				velocity = { 0, 0 };
			}
			
			frame++;
			if (frame > maxFrame) {
				frame = 1;
			}



		}
	}
}


Player::~Player()
{
}
