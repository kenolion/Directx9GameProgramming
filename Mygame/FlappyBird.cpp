#include "FlappyBird.h"



bool FlappyBird::initializeGame(HWND hwnd)
{
	Game::initializeGame(hwnd);
	sound->playMainMenuMusic(); 
	sound->channel->setVolume(0.4f);
	object[1] = new Player(50.0f, (float)(GAME_HEIGHT / 2), D3DXVECTOR2(1.0f, 1.0f), 10, 2.0f, 5);
	object[0] = new Pictures(0.0f, 0.0f, D3DXVECTOR2(1.0f, 1.0f));
	if (!object[0]->initialize(graphics->device3d, "sprite\\skybackground.png", 1280, 720, 1, 1, true, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0, 0, 0, 0)) {
		MessageBox(NULL, "There was an issue creating the sprite", NULL, NULL);			//Device3d,sprite file name, width , height , row,collumn
		return initialize = false;
	}
	if (!object[1]->initialize(graphics->device3d, "sprite\\ben.png", 128, 192, 4, 4, true, D3DCOLOR_XRGB(0, 0, 0), 0.80f, 0, 0, 0, 0)) {
		MessageBox(NULL, "There was an issue creating the sprite", NULL, NULL);			//Device3d,sprite file name, width , height , row,collumn
		return initialize = false;
	}
	for (int i = 2; i < 7; i++) {
		object[i] = new Enemy(i*200.0f, 609.0f, D3DXVECTOR2(1.0f, 2.0f), 10, 2.0f, 5);
		if (!object[i]->initialize(graphics->device3d, "sprite\\pipestanding.png", 48, 111, 1, 1, true, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0, 0, 0, 0)) {
			MessageBox(NULL, "There was an issue creating the sprite", NULL, NULL);			//Device3d,sprite file name, width , height , row,collumn
			return initialize = false;
		}
	}
	for (int i = 7; i < 12; i++) {
		object[i] = new Enemy((i-5)*200.0f, 0.0f, D3DXVECTOR2(1.0f, 1.5f), 10, 2.0f, 5);
		if (!object[i]->initialize(graphics->device3d, "sprite\\upsidedownPipe.png", 46, 114, 1, 1, true, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0, 0, 0, 0)) {
			MessageBox(NULL, "There was an issue creating the sprite", NULL, NULL);			//Device3d,sprite file name, width , height , row,collumn
			return initialize = false;
		}
	}

	
	
	
	gravity = { 0,GRAVITY };
	object[1]->setState(3);

}

void FlappyBird::update(int gameTime)
{
	for (int i = 0; i < FLAPPYBIRDOBJECTS; i++) {
		object[i]->update(gameTime);

	}
	cursor->update(gameTime);
}

void FlappyBird::draw()
{
	graphics->clear(D3DCOLOR_XRGB(0, 100, 100));
	graphics->begin();
	object[0]->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	for (int i = 0; i < FLAPPYBIRDOBJECTS; i++) {
		object[i]->draw();
	}
	cursor->draw();
	object[0]->sprite->End();
	graphics->end();
	graphics->present();
}

void FlappyBird::collisions()
{

	object[1]->forceVector = { 0,0 };
	if (input->upArrowKey && !(object[1]->jump)) {
		object[1]->jump = true;
		object[1]->forceVector = { 0,-115 };
		std::cout << object[1]->forceVector.y << std::endl;
	}
	
	object[1]->setAcceleration(object[1]->forceVector / object[1]->getMass());
	object[1]->setVelocity(object[1]->getVelocity() + object[1]->getAcceleration());
	if (object[1]->jumpCD >= 40 && input->upArrowKey) {
		object[1]->jump = false;
		object[1]->jumpCD = 0;
	}
	else {
		object[1]->setVelocity(D3DXVECTOR2(0, object[1]->getVelocityY()) + gravity);
	}

	for (int i = 0; i < FLAPPYBIRDOBJECTS; i++) {
		if (i == 1)i++;
		object[i]->setVelocity(D3DXVECTOR2(-2, object[i]->getVelocityY()));
	}
	for (int i = 2; i < FLAPPYBIRDOBJECTS; i++) {
		object[1]->enemyCollision = object[1]->collideWith(*object[i], object[1]->posVector);
		if (object[1]->enemyCollision) {
			std::cout << object[i]->getObjectX();
			object[1]->setStatus(ObjectStatus::Dead);
		}

	}
	if (object[1]->getStatus() == ObjectStatus::Dead) {
		sound->pauseMainMenuMusic();
		state = GameStates::LEVELPLAYERWIN;
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
