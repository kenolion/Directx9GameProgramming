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
	// initialize device
	if (!graphics->initialize(hwnd, GAME_WIDTH, GAME_HEIGHT)) {
		MessageBox(NULL, "There was an issue initializing the graphics", NULL, NULL);
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
			input->remapKeys();//<---- underconstruction used to remap keys but needs to be switched to windows input instead of directinput

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
	dltPtr(gameTime);
	dltPtr(input);



}

