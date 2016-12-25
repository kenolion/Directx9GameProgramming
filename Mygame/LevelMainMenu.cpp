#include "LevelMainMenu.h"



bool LevelMainMenu::initializeGame(HWND hwnd)
{
	Game::initializeGame(hwnd);

	startButton = new Button(0, 0, D3DXVECTOR2(1.0f, 1.0f)); //X to print, Y to print position and scaling.

	if(!startButton->initialize(graphics->device3d, "sprite\\buttonA.png", 1280, 720, 1,1, true, D3DCOLOR_XRGB(0,0,0))) //Width, Height of the pic when printed in game, SpriteWidth, SpriteHeight, 
	{
		MessageBox(NULL, "There was an issue creating the start button", NULL, NULL);
		return initialize = false; //If false program wont run
	}
	return true;
}

void LevelMainMenu::update(int gameTime)
{
	cursor->update(gameTime, D3DXVECTOR2(mouseX, mouseY), D3DXVECTOR2(0, 0)); //Update cursor according to mouseX and mouseY
}

void LevelMainMenu::collisions()
{

}

void LevelMainMenu::draw()
{
	graphics->clear(D3DCOLOR_XRGB(0, 100, 100));
	graphics->begin();
	
	//UserInterface=> Draw Main Menu Button
	//UserInterface=> Draw Pause UI
	startButton->draw();
	//Button Class , On hover
	cursor->draw();
//	graphics->lineBegin(); //Zer Add - Basically has line->Begin() in it.
	//userinterface->drawUIButton(graphics->line, 20, 20, 100, 100, 200, 200, 300, 300, 400, 400);
//	graphics->lineEnd(); //Zer Add -  //Basically has Line->End() in it.

	graphics->end();  
	graphics->present();
}

void LevelMainMenu::deleteAll()
{
	Game::deleteAll();
}


LevelMainMenu::LevelMainMenu()
{
}


LevelMainMenu::~LevelMainMenu()
{
}

