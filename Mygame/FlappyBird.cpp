#include "FlappyBird.h"



bool FlappyBird::initializeGame(HWND hwnd)
{
	Game::initializeGame(hwnd);
	object[0] = new Player(50.0f,(float)(GAME_HEIGHT/2),D3DXVECTOR2(1.0f,1.0f),10,2.0f,5);



	if (!object[0]->initialize(graphics->device3d, "sprite\\ben.png", 128, 192, 4, 4, true, D3DCOLOR_XRGB(0, 0, 0), 0.70f)) {
		MessageBox(NULL, "There was an issue creating the sprite", NULL, NULL);			//Device3d,sprite file name, width , height , row,collumn
		return initialize = false;
	}

	object[0]->setState(3);

}

void FlappyBird::update(int gameTime)
{
	for (int i = 0; i < FLAPPYBIRDOBJECTS; i++) {
		object[i]->update(gameTime);

	}
}

void FlappyBird::draw()
{
	for (int i = 0; i < FLAPPYBIRDOBJECTS; i++) {
		object[i]->draw();

	}
}

void FlappyBird::collisions()
{
	if (input->upArrowKey) {
		object[0]->forceVector = { 0,-5 };
	}
	object[0]->setAcceleration(object[0]->forceVector/ object[0]->getMass());
	object[0]->setVelocity(object[0]->getVelocity()+object[0]->getAcceleration());
	object[0]->setVelocity(D3DXVECTOR2(2,object[0]->getVelocityY()));


	for (int i = 1; i < FLAPPYBIRDOBJECTS; i++) {
		object[0]->collideWith(*object[i], object[0]->posVector);

	}



}

void FlappyBird::deleteAll()
{
}

FlappyBird::FlappyBird()
{
}


FlappyBird::~FlappyBird()
{
}
