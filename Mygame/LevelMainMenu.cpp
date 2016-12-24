#include "LevelMainMenu.h"



bool LevelMainMenu::initializeGame(HWND hwnd)
{
	Game::initializeGame(hwnd);
	graphics->createLine();
	return true;
}

void LevelMainMenu::update(int gameTime)
{

}

void LevelMainMenu::collisions()
{

}

void LevelMainMenu::draw()
{
	graphics->clear(D3DCOLOR_XRGB(0, 0, 0));
	graphics->begin();

	//UserInterface=> Draw Main Menu Button
	//UserInterface=> Draw Pause UI

	//Button Class , On hover

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

