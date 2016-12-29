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
	if(graphics == NULL){
	graphics = new Graphics();
	if (!graphics->initialize(hwnd, GAME_WIDTH, GAME_HEIGHT)) {
		MessageBox(NULL, "There was an issue initializing the graphics", NULL, NULL);
		return initialize = false;
	}

	}
	input = new PlayerInput();
	sound = new DxSound();
	cursor = new Cursor(GAME_WIDTH/2,GAME_HEIGHT/2, D3DXVECTOR2(1.0f, 1.0f), 11); //6 is 10 frames per second

	// initialize device
	
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

	input->getInput();												//A function that detects for input 
	input->ReadMouse();												//Read the mouse Device
	input->convertRelativeToAbsolute();								//Converts Relative X and Y mouse position to Absolute position
	input->GetMouseLocation(mouseX, mouseY);						//Stores the converted absolute position to the Input class's mouseX and mouseY variable

	cursor->posVector = { (float)mouseX,(float)mouseY };			//Sets the Cursor Position to the Absolute MouseX and MouseY in the window.
	
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
	dltPtr(gameTime);
	dltPtr(input);
	dltPtr(sound);
	dltPtr(cursor);
	dltPtr(userinterface);


}

