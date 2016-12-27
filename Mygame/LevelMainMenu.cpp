#include "LevelMainMenu.h"



bool LevelMainMenu::initializeGame(HWND hwnd)
{
	Game::initializeGame(hwnd);
	sound->playMainMenuMusic();
	sound->channel->setVolume(0.4f);
	//======================================================= Create your Game Objects Here =======================================================
	backgroundImage = new Pictures(0.0f, 0.0f, D3DXVECTOR2(1.0f, 1.0f)); //x, y, scaling, animation, speed,mass
	if (!backgroundImage->initialize(graphics->device3d, "sprite\\backgroundimage.png", 1280, 720, 1, 1, true, D3DCOLOR_XRGB(0, 0, 0), 1.0f,0,0,0,0)) {
		MessageBox(NULL, "There was an issue creating the backgroundImage", NULL, NULL);			//Device3d,sprite file name, width , height , row,collumn
		return initialize = false;
	}
	//---------------------------------------------------------------------------------------------------------------------------------------------
	gameLogo = new Pictures(100,100, D3DXVECTOR2(1.0f, 1.0f));
	if (!gameLogo->initialize(graphics->device3d, "sprite\\gameLogo.png", 1130, 97, 1, 1, true, D3DCOLOR_XRGB(0, 0, 0), 1.0f,0,0,0,0)) {
		MessageBox(NULL, "There was an issue creating the game logo image", NULL, NULL);			//Device3d,sprite file name, width , height , row,collumn
		return initialize = false;
	}

	//---------------------------------------------------------------------------------------------------------------------------------------------

	startButton = new Button(0, 0, D3DXVECTOR2(1.0f, 1.0f),30, "Start Game", 10, 255,155,0); //X to print, Y to print position and scaling.
	startButton->setX(50);
	startButton->setY(600);


	if(!startButton->initialize(graphics->device3d, "sprite\\buttonTemplateAnimation.png", 1116, 76, 1, 4, true, D3DCOLOR_XRGB(255,255,255),1.0f,0,0,0,0)) //Width, Height of the pic when printed in game, SpriteWidth, SpriteHeight, 
	{
		MessageBox(NULL, "There was an issue creating the start button", NULL, NULL);
		return initialize = false; //If false program wont run
	}
	//---------------------------------------------------------------------------------------------------------------------------------------------
	quitButton = new Button(0, 0, D3DXVECTOR2(1.0f, 1.0f), 30, "Exit Game", 10, 255, 155, 0);
	quitButton->setX(950);
	quitButton->setY(600);

	if (!quitButton->initialize(graphics->device3d, "sprite\\buttonTemplateAnimation.png", 1116, 76, 1, 4, true, D3DCOLOR_XRGB(255, 255, 255), 1.0f,0,0,0,0)) //Width, Height of the pic when printed in game, SpriteWidth, SpriteHeight, 
	{
		MessageBox(NULL, "There was an issue creating the quit button", NULL, NULL);
		return initialize = false; //If false program wont run
	}
	
	//---------------------------------------------------------------------------------------------------------------------------------------------
	
	//Enemy Goomba Testing
	goombaOne = new Enemy(1280.0f,550.0f, D3DXVECTOR2(1.0f, 1.0f), 10, 2, 5);
	if (!goombaOne->initialize(graphics->device3d, "sprite\\goombawalkLeft.png", 168, 31, 1, 8, true, D3DCOLOR_XRGB(255, 255, 255), 1.0f,0,0,0,0))
	{
		MessageBox(NULL, "There was an issue creating goomba one", NULL, NULL);
		return initialize = false; //If false program wont run
	}
	

	//==============================================================================================================================================
	return true;

}

void LevelMainMenu::update(int gameTime)
{

	
	cursor->update(gameTime); //Update cursor according to mouseX and mouseY

	//---------------------------------------------------------------------------------------------------------------------------------------------

	Button *childrenPointer = dynamic_cast<Button*>(startButton); //Children class = Parent 

	if (childrenPointer->onHover(mouseX, mouseY)) 
	{
		if (childrenPointer->isClicked(input->leftClickDown))
		{
			//change to level one
			state = GameStates::LEVEL1;
			sound->pauseMainMenuMusic();
		}
		startButton->update(gameTime);
	}
	else{
		startButton->setFrame(1);
	}

	//---------------------------------------------------------------------------------------------------------------------------------------------

	Button *childrenPointer2 = dynamic_cast<Button*>(quitButton); //Children class = Parent class
	
	if (childrenPointer2->onHover(mouseX, mouseY))
	{
		if (childrenPointer->isClicked(input->leftClickDown))
		{
			//quit game; Game state = (something) to quit
			state = GameStates::EXITPROGRAM;
		}
		quitButton->update(gameTime);
	}
	else {
		quitButton->setFrame(1);
	}

	//---------------------------------------------------------------------------------------------------------------------------------------------
	//goombaVector[0] = D3DXVECTOR2(goombaOne->hitBoxTop+100, goombaOne->hitBoxBottom+100), D3DXVECTOR2(goombaOne->hitBoxBottom+ 100, goombaOne->hitBoxRight) , D3DXVECTOR2(goombaOne->hitBoxRight, goombaOne->hitBoxTop+goombaOne->hitBoxRight) , D3DXVECTOR2(goombaOne->hitBoxTop + goombaOne->hitBoxRight, goombaOne->hitBoxTop);
	////goombaVector[0] = D3DXVECTOR2(goombaOne->hitBoxTop,goombaOne->getObjectY()+5);      //first point aka top left point
	////goombaVector[1] = D3DXVECTOR2(goombaOne->hitBoxTop, goombaOne->getObjectY()+30);	//second point aka bottom left point
	////goombaVector[2] = D3DXVECTOR2(goombaOne->hitBoxTop+20, goombaOne->getObjectY()+30);	//third point aka bottom right point
	////goombaVector[3] = D3DXVECTOR2(goombaOne->hitBoxTop+20,goombaOne->getObjectY()+5);	//fourth point aka top right point
	////goombaVector[4] = D3DXVECTOR2(goombaOne->hitBoxTop, goombaOne->getObjectY()+5);		//fifth point aka top left point
	goombaOne->update(gameTime);
	

	
}

void LevelMainMenu::collisions()
{
	//Collision should not update players position
//	for (int i = 0; i<GOBJECTNUML1; i++) {
//		object[i]->posVector = object[i]->getObjectPos();
//	}

	goombaOne->posVector = goombaOne->getObjectPos();
}

void LevelMainMenu::draw()
{
	graphics->clear(D3DCOLOR_XRGB(0,0,0)); //255 204 255 = Pink
	graphics->begin();

	graphics->createLine();
	graphics->lineBegin();

	cursor->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	//======================================================= Draw your Objects in Here =======================================================

	backgroundImage->draw();
	gameLogo->draw();
	goombaOne->draw();

	//graphics->drawLine(goombaVector, 5, 255, 204, 255);

	//std::cout << std::endl << goombaOne->hitBoxTop << std::endl << goombaOne->hitBoxBottom << std::endl << goombaOne->hitBoxLeft << std::endl << goombaOne->hitBoxRight << std::endl;
	startButton->draw();
	quitButton->draw();
	

	//==============================================================================================================================================
	cursor->draw();
	cursor->sprite->End();

	graphics->lineEnd();

	graphics->end();  
	graphics->present();
}

void LevelMainMenu::deleteAll()
{
	Game::deleteAll();
	
	dltPtr(startButton);
	dltPtr(quitButton);
	dltPtr(goombaOne);
	dltPtr(backgroundImage);
	dltPtr(gameLogo);
	
		
}		


LevelMainMenu::LevelMainMenu()
{
}


LevelMainMenu::~LevelMainMenu()
{
}

