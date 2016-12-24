#include "Level1.h"



bool Level1::initializeGame(HWND hwnd)
{
	Game::initializeGame(hwnd);
	player = new Player(50.0f, 50.0f, (float)M_PI_4, D3DXVECTOR2(1.0f, 1.0f), 1.0f, 1); //x ,y ,rotation,
	player2 = new Player(100.0f, 50.0f, 0, D3DXVECTOR2(1.0f, 1.0f), 1.0f, 1);//x ,y ,rotation,speed,maxspeed

	// initialize texture
	if (!player->initialize(graphics->device3d, "sprite\\practical9.png", 64, 64, 2, 2, false)) {
		MessageBox(NULL, "There was an issue creating the sprite", NULL, NULL);			//Device3d,sprite file name, width , height , row,collumn
		return initialize = false;
	}
	if (!player2->initialize(graphics->device3d, "sprite\\practical9.png", 64, 64, 2, 2, false)) {
		MessageBox(NULL, "There was an issue creating the sprite", NULL, NULL);
		return initialize = false;
	}
	pan = 0.0f;
	frequency = 44000.0f;
	player2->setState(2); //<----- state set to 2 because state controls the column of the image in this case
	return true;
}

void Level1::update(int gameTime)
{

	player->update(gameTime, posVector, forceVector);
	player2->update(gameTime, D3DXVECTOR2(0, 0), D3DXVECTOR2(0, 0));				// position vector temporarily set to 0

}

void Level1::collisions()
{

	//Collision should not update players position

	posVector = player->getObjectPos();
	forceVector = player->getForce();

	if (input->rightArrowKey) {

		player->rotation += 0.1f;
		if (pan <= 1) {
			std::cout << frequency;
			//sound->channel->setPan(pan+=0.01f);
			sound->channel->setFrequency(frequency+=10);
		}
	}
	if (input->leftArrowKey) {
		player->rotation -= 0.1f;
		if (pan >= -1) {
			std::cout << frequency;
			sound->channel->setFrequency(frequency -= 10);
			//sound->channel->setPan(pan -= 0.01f);
		}
	}

	if (input->upArrowKey) {
		forceVector = D3DXVECTOR2(sin(player->rotation)*player->enginePower, -cos(player->rotation)*player->enginePower);
		player->setAcceleration(forceVector / player->getMass());				// acceleration =force/ mass 
		player->setVelocity(player->getVelocity() + player->getAcceleration());	// velocity = velocity +acceleration;
	}

	player->collision = player->collideWith(*player2, posVector);

}

void Level1::draw()
{
	//Simple RGB value for background so use XRGB
	 //Draws sprite and other game object
	graphics->clear(D3DCOLOR_XRGB(0, 0, 0)); 
	graphics->begin();
	
	if (player) {
		player2->draw();
		player->draw();
	}

	graphics->end();
	graphics->present();

}

void Level1::deleteAll()
{
	Game::deleteAll();
	dltPtr(player);
	dltPtr(player2);

}

Level1::Level1()
{
}


Level1::~Level1()
{

}


