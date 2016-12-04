#include "Level1.h"



bool Level1::initializeGame(HWND hwnd)
{
	Game::initializeGame(hwnd);
	player = new GameObject(50.0f, 50.0f, (float)M_PI_4, 1.0f, 20.0f); //x ,y ,rotation,speed,maxspeed
	player2 = new GameObject(200.0f, 200.0f, 0, 0, 0);//x ,y ,rotation,speed,maxspeed

	// initialize texture
	if (!player->initialize(graphics->device3d, "sprite\\sprite_test.jpg", 384, 128, 1, 3)) {
		MessageBox(NULL, "There was an issue creating the sprite", NULL, NULL);			//Device3d,sprite file name, width , height , row,collumn
		return initialize = false;
	}
	if (!player2->initialize(graphics->device3d, "sprite\\PlayerPaper.png", 58, 86, 1, 1)) {
		MessageBox(NULL, "There was an issue creating the sprite", NULL, NULL);
		return initialize = false;
	}
	return true;
}

void Level1::update(int gameTime)
{
	player->update(gameTime);

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

		//setDrawingPoint(0, 0);

	}

	graphics->end();
	graphics->present();

}

void Level1::deleteAll()
{
	Game::deleteAll();
	dltPtr(player);
	dltPtr(player2);
	std::cout << "TEST";
}

Level1::Level1()
{
}


Level1::~Level1()
{
	
}


