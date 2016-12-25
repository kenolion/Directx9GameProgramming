#include "Button.h"



Button::Button(float x, float y, D3DXVECTOR2 scaling) : GameObject(x, y, scaling)
{
}


Button::~Button()
{
}



void Button::update(int &gameTime, D3DXVECTOR2 &position, D3DXVECTOR2 &force)
{
	std::cout << "X:" << position.x << "   " << std::endl;
	std::cout << "Y:" << position.y << "   " << std::endl;
	std::cout << "Velocity:" << velocity.x << "," << velocity.y << "   " << std::endl;
	if (status == ObjectStatus::Active) {

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

