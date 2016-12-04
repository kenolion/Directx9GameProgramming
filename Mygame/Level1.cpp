#include "Level1.h"



bool Level1::initializeGame(HWND hwnd)
{
	Game::initializeGame(hwnd);
	player = new Player(50.0f, 50.0f, (float)M_PI_4); //x ,y ,rotation,speed,maxspeed
	player2 = new Player(200.0f, 200.0f, 0);//x ,y ,rotation,speed,maxspeed

	// initialize texture
	if (!player->initialize(graphics->device3d, "sprite\\practical9.png", 64, 64, 2, 2,false)) {
		MessageBox(NULL, "There was an issue creating the sprite", NULL, NULL);			//Device3d,sprite file name, width , height , row,collumn
		return initialize = false;
	}
	if (!player2->initialize(graphics->device3d, "sprite\\practical9.png", 64, 64, 2, 2,false)) {
		MessageBox(NULL, "There was an issue creating the sprite", NULL, NULL);
		return initialize = false;
	}
	player2->setState(2); //<----- state set to 2 because state controls the column of the image in this case
	return true;
}

void Level1::update(int gameTime)
{
	
	player->update(gameTime,input->keyPressed);
	player2->update(gameTime, input->keyPressed);

}

void Level1::collisions()
{
	player->collision = player->collideWith(*player2);
	if (input->upArrowKey) {
		player->setAcceleration(D3DXVECTOR3(0, -1, 0));
	}
	if (input->downArrowKey) {
		player->setAcceleration(D3DXVECTOR3(0, 1, 0));
	}
	if (input->rightArrowKey) {
		player->setAcceleration(D3DXVECTOR3(1, 0, 0));
	}
	if (input->leftArrowKey) {
		player->setAcceleration(D3DXVECTOR3(-1, 0, 0));
	}


}

void Level1::draw()
{
	//Simple RGB value for background so use XRGB
	 //Draws sprite and other game object
	graphics->clear(D3DCOLOR_XRGB(0, 100, 100));
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


