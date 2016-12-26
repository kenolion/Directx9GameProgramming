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
	input = new PlayerInput();
	sound = new DxSound();
	cursor = new Cursor(GAME_WIDTH/2,GAME_HEIGHT/2, D3DXVECTOR2(1.0f, 1.0f), 11); //6 is 10 frames per second

	// initialize device
	if (!graphics->initialize(hwnd, GAME_WIDTH, GAME_HEIGHT)) {
		MessageBox(NULL, "There was an issue initializing the graphics", NULL, NULL);
		return initialize = false;
	}
	if (!cursor->initialize(graphics->device3d, "sprite/dankcursor.png" ,1440,95, 1,15 ,true, D3DCOLOR_XRGB(255,0,255),1.0f,0,0,0,0)) { 
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

	if (!sound->initializeSound()) {
		MessageBox(NULL, "There was an issue initializing the Sounds", NULL, NULL);
		return initialize = false;
	}
	
	sound->loadSounds();
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
	setDrawingPoint(0, 0);
	collisions();
	update(framesToUpdate);
	draw();// draws the games graphics


}

//Draws game object


LRESULT Game::messageHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)		//Windows procedure
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
			//case VK_F1:
			//	input->remapKeys();//<---- underconstruction used to remap keys but needs to be switched to windows input instead of directinput

				//break;
		}
		break;
	case WM_LBUTTONDOWN:
		break;

	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

void Game::deleteAll() {
	graphics->cleanup();
	dltPtr(graphics);
	dltPtr(gameTime);
	dltPtr(input);
	dltPtr(sound);
	dltPtr(cursor);



}

