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
	if (graphics == NULL) {
		graphics = new Graphics();
		if (!graphics->initialize(hwnd, GAME_WIDTH, GAME_HEIGHT)) {
			MessageBox(NULL, "There was an issue initializing the graphics", NULL, NULL);
			return initialize = false;
		}

	}
	if (sound == NULL) {
		sound = new DxSound();
		if (!sound->initializeSound()) {
			MessageBox(NULL, "There was an issue initializing the Sounds", NULL, NULL);
			return initialize = false;
			
		}
		sound->loadSounds();
	}
	input = new PlayerInput();

	cursor = new Cursor(GAME_WIDTH / 2, GAME_HEIGHT / 2, D3DXVECTOR2(1.0f, 1.0f), 11); //6 is 10 frames per second

	// initialize device

	if (!cursor->initialize(graphics->device3d, "sprite/dankcursor.png", 1440, 95, 1, 15, true, D3DCOLOR_XRGB(255, 0, 255), 1.0f)) {
		MessageBox(NULL, "There was an issue initializing the graphics", NULL, NULL);
		return initialize = false;
	}
	if (!input->initializeKeyboard(hwnd)) {
		MessageBox(NULL, "There was an issue initializing the Keyboard input", NULL, NULL);
		return initialize = false;
	}

	if (!input->initializeMouse(hwnd)) {
		MessageBox(NULL, "There was an issue initializing the Mouse input", NULL, NULL);
		return initialize = false;
	}




	//sound->playSoundtrack();


	gameTime = new GameTime();

	if (!gameTime->initialize(60)) {
		return initialize = false;
	}
	return initialize = true;

}


void Game::run()	// This function is called repeatedly by main message loop
{
	framesToUpdate = gameTime->update();

	/*
	1.Input
	2.AI
	3.Collision
	4.Render
	*/

	input->getInput();
	input->ReadMouse();
	input->ProcessInput();
	input->GetMouseLocation(mouseX, mouseY);
	cursor->posVector = { (float)mouseX,(float)mouseY };
	//std::cout << "Mouse X : "<< mouseX << "          " "Mouse Y : " << mouseY << "          ";
	//setDrawingPoint(0, 0);
	collisions();
	update(framesToUpdate);
	draw();// draws the games graphics


}

//Draws game object
void Game::deletegraphics() {
	graphics->cleanup();
	dltPtr(graphics);

}


void Game::deleteAll() {
	//graphics->cleanup();
	//dltPtr(graphics);
	dltPtr(sound);
	dltPtr(gameTime);
	dltPtr(input);
	dltPtr(cursor);
	dltPtr(userinterface);


}

