#include "LevelMainMenu.h"



bool LevelMainMenu::initializeGame(HWND hwnd)
{
	Game::initializeGame(hwnd);
	
	startButton = new Button(0, 0, D3DXVECTOR2(1.0f, 1.0f),30, "Start Game", 10, 100,100,100); //X to print, Y to print position and scaling.
	startButton->setX(50);
	startButton->setY(600);

	if(!startButton->initialize(graphics->device3d, "sprite\\buttonTemplateAnimation.png", 1116, 76, 1, 4, true, D3DCOLOR_XRGB(255,255,255))) //Width, Height of the pic when printed in game, SpriteWidth, SpriteHeight, 
	{
		MessageBox(NULL, "There was an issue creating the start button", NULL, NULL);
		return initialize = false; //If false program wont run
	}

	quitButton = new Button(0, 0, D3DXVECTOR2(1.0f, 1.0f), 30, "Exit Game", 10, 100, 100, 100);
	quitButton->setX(950);
	quitButton->setY(600);

	if (!quitButton->initialize(graphics->device3d, "sprite\\buttonTemplateAnimation.png", 1116, 76, 1, 4, true, D3DCOLOR_XRGB(255, 255, 255))) //Width, Height of the pic when printed in game, SpriteWidth, SpriteHeight, 
	{
		MessageBox(NULL, "There was an issue creating the quit button", NULL, NULL);
		return initialize = false; //If false program wont run
	}
	return true;


}

void LevelMainMenu::update(int gameTime)
{

	cursor->posVector = { (float)mouseX,(float)mouseY };
	cursor->update(gameTime); //Update cursor according to mouseX and mouseY
	Button *childrenPointer = dynamic_cast<Button*>(startButton); //Children class = Parent 

	if (childrenPointer->onHover(mouseX, mouseY)) 
	{
		startButton->update(gameTime);
	}
	else{
		startButton->setFrame(1);
	}
	Button *childrenPointer2 = dynamic_cast<Button*>(quitButton); //Children class = Parent class
	
	if (childrenPointer2->onHover(mouseX, mouseY))
	{
		quitButton->update(gameTime);
	}
	else {
		quitButton->setFrame(1);
	}
}

void LevelMainMenu::collisions()
{
	


}

void LevelMainMenu::draw()
{
	graphics->clear(D3DCOLOR_XRGB(0, 100, 100));
	graphics->begin();
	cursor->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	//UserInterface=> Draw Main Menu Button
	//UserInterface=> Draw Pause UI
	startButton->draw();
	quitButton->draw();

	//Button Class , On hover
	cursor->draw();
//	graphics->lineBegin(); //Zer Add - Basically has line->Begin() in it.
	//userinterface->drawUIButton(graphics->line, 20, 20, 100, 100, 200, 200, 300, 300, 400, 400);
//	graphics->lineEnd(); //Zer Add -  //Basically has Line->End() in it.
	cursor->sprite->End();
	graphics->end();  
	graphics->present();
}

void LevelMainMenu::deleteAll()
{
	Game::deleteAll();
	dltPtr(startButton);
	dltPtr(quitButton);
}


LevelMainMenu::LevelMainMenu()
{
}


LevelMainMenu::~LevelMainMenu()
{
}

