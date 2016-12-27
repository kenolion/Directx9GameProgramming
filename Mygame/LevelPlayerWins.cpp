#include "LevelPlayerWins.h"


bool LevelPlayerWins::initializeGame(HWND hwnd)
{
	Game::initializeGame(hwnd);
	
	sound->playPlayerWinMusic();
	
	//======================================================= Create your Game Objects Here =======================================================
	backgroundImage = new Pictures(0.0f, 0.0f, D3DXVECTOR2(1.0f, 1.0f)); //x, y, scaling, animation, speed,mass
	if (!backgroundImage->initialize(graphics->device3d, "sprite\\backgroundImage.png", 1280, 720, 1, 1, true, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0 ,0 ,0 ,0)) {
		MessageBox(NULL, "There was an issue creating the backgroundImage", NULL, NULL);			//Device3d,sprite file name, width , height , row,collumn
		return initialize = false;
	}
	//---------------------------------------------------------------------------------------------------------------------------------------------
	youWinTextLogo = new Pictures(200, 100, D3DXVECTOR2(1.0f, 1.0f));
	if (!youWinTextLogo->initialize(graphics->device3d, "sprite\\youWinLogo.png", 891, 179, 1, 1, true, D3DCOLOR_XRGB(0, 0, 0),1.0f, 0,0,0,0)) {
		MessageBox(NULL, "There was an issue creating the game logo image", NULL, NULL);			//Device3d,sprite file name, width , height , row,collumn
		return initialize = false;
	}

	//---------------------------------------------------------------------------------------------------------------------------------------------

	returnToMainMenuButton = new Button(0, 0, D3DXVECTOR2(1.0f, 1.0f), 30, " Main Menu", 10, 255, 155, 0); //X to print, Y to print position and scaling.
	returnToMainMenuButton->setX(50);
	returnToMainMenuButton->setY(600);

	if (!returnToMainMenuButton->initialize(graphics->device3d, "sprite\\buttonTemplateAnimation.png", 1116, 76, 1, 4, true, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0, 0, 0, 0)) //Width, Height of the pic when printed in game, SpriteWidth, SpriteHeight, 
	{
		MessageBox(NULL, "There was an issue creating the start button", NULL, NULL);
		return initialize = false; //If false program wont run
	}
	//---------------------------------------------------------------------------------------------------------------------------------------------

	quitButton = new Button(0, 0, D3DXVECTOR2(1.0f, 1.0f), 30, "Exit Game", 10, 255, 155, 0);
	quitButton->setX(950);
	quitButton->setY(600);

	if (!quitButton->initialize(graphics->device3d, "sprite\\buttonTemplateAnimation.png", 1116, 76, 1, 4, true, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0, 0, 0, 0)) //Width, Height of the pic when printed in game, SpriteWidth, SpriteHeight, 
	{
		MessageBox(NULL, "There was an issue creating the quit button", NULL, NULL);
		return initialize = false; //If false program wont run
	}
	

}

void LevelPlayerWins::update(int gameTime)
{

	cursor->posVector = { (float)mouseX,(float)mouseY };
	cursor->update(gameTime); //Update cursor according to mouseX and mouseY

	Button *childrenPointer1 = dynamic_cast<Button*>(returnToMainMenuButton); //Children class = Parent 

	if (childrenPointer1->onHover(mouseX, mouseY))
	{
		if (childrenPointer1->isClicked(input->leftClickDown))
		{
			//returnToMainMenu
			state = GameStates::MENU;
			sound->pausePlayerWinMusic();
		}
		returnToMainMenuButton->update(gameTime);
	}
	else {
		returnToMainMenuButton->setFrame(1);
	}

	Button *childrenPointer2 = dynamic_cast<Button*>(quitButton); //Children class = Parent class

	if (childrenPointer2->onHover(mouseX, mouseY))
	{
		if (childrenPointer2->isClicked(input->leftClickDown))
		{
			//quitgame
			state = GameStates::EXITPROGRAM;
		}
		quitButton->update(gameTime);
	}
	else {
		quitButton->setFrame(1);
	}
}

void LevelPlayerWins::collisions()
{
	//Collision should not update players position
	//	for (int i = 0; i<GOBJECTNUML1; i++) {
	//		object[i]->posVector = object[i]->getObjectPos();
	//	}


}

void LevelPlayerWins::draw()
{
	graphics->clear(D3DCOLOR_XRGB(255, 204, 255)); //255 204 255 = Pink
	graphics->begin();

	cursor->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	//======================================================= Draw your Objects in Here =======================================================

	backgroundImage->draw();
	youWinTextLogo->draw();

	returnToMainMenuButton->draw();
	quitButton->draw();

	//==============================================================================================================================================
	cursor->draw();
	cursor->sprite->End();

	graphics->end();
	graphics->present();
}

void LevelPlayerWins::deleteAll()
{
	Game::deleteAll();
	dltPtr(youWinTextLogo);
	dltPtr(backgroundImage);
	dltPtr(returnToMainMenuButton);
	
}

LevelPlayerWins::LevelPlayerWins()
{
}


LevelPlayerWins::~LevelPlayerWins()
{
}

