#include "Game.h"

Game::Game()
{

	initialize = false;
	graphics = NULL;
}


Game::~Game()
{
}

bool Game::initializeGame(HWND hwnd)
{
	this->hwnd = hwnd;
	graphics = new Graphics();
	player = new GameObject(50.0f, 50.0f, (float)M_PI_4, 1.0f, 20.0f); //x ,y ,rotation,speed,maxspeed
	player2 = new GameObject(200.0f, 200.0f, 0, 0, 0);//x ,y ,rotation,speed,maxspeed
	input = new PlayerInput();
	// initialize device
	if (!graphics->initialize(hwnd, GAME_WIDTH, GAME_HEIGHT)) {
		MessageBox(NULL, "There was an issue initializing the graphics", NULL, NULL);
		return initialize = false;
	}



	
	
	// initialize texture
	if (!player->initialize(graphics->device3d, "sprite\\sprite_test.jpg", 384, 128, 1, 3)) {
		MessageBox(NULL, "There was an issue creating the sprite", NULL, NULL);			//Device3d,sprite file name, width , height , row,collumn
		return initialize = false;
	}
	if (!player2->initialize(graphics->device3d, "sprite\\PlayerPaper.png", 58, 86, 1, 1)) {
		MessageBox(NULL, "There was an issue creating the sprite", NULL, NULL);
		return initialize = false;
	}
	if (!input->initializeInput(hwnd)) {
		std::cout << "failed to initialize input";
		return initialize = false;
	}

	gameTime = new GameTime();

	if (!gameTime->initialize(1)) {
		return initialize = false;
	}
	return initialize = true;

}
// This function is called repeatedly by main message loop
void Game::run()
{
	framesToUpdate = gameTime->update();

	if (initialize) {
		/*
		1.Input
		2.AI
		3.Collision
		4.Render
		*/
		input->getInput();
		
		update(framesToUpdate);
		draw();// draws the games graphics
	}

}

//Draws game object
void Game::draw()
{
	//Simple RGB value for background so use XRGB
	// Draws sprite and other game object
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

void Game::update(float gameTime)
{

	//Update sprites and other game object
	if (player)
		player->update(gameTime);


	if (player2)
		player2->update(gameTime);

}

LRESULT Game::messageHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{


	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
		break;
	case WM_KEYDOWN:

		switch (wParam) {
		case VK_ESCAPE:
			PostQuitMessage(0);
			return 0;
			break;
		case VK_F1:
			input->remapKeys();

			break;
		}
		break;
	case WM_LBUTTONDOWN:
		input->DI_Device->Acquire();

		break;

	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}


void Game::setDrawingPoint(int x, int y)
{
	COORD coord; //Does not need to be define because if we right click COORD and go to definition it is already defined in another library
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void Game::deleteAll() {
	graphics->cleanup();
	dltPtr(graphics);
	dltPtr(player);
	dltPtr(player2);
	dltPtr(gameTime);
	dltPtr(input);



}

