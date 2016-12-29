#include "FlappyBird.h"



bool FlappyBird::initializeGame(HWND hwnd)
{
	Game::initializeGame(hwnd);
	sound->playMainMenuMusic();
	sound->channel->setVolume(0.4f);
	object[1] = new Player(50.0f, (float)(GAME_HEIGHT / 2), D3DXVECTOR2(1.0f, 1.0f), 10, 2.0f, 5);
	object[0] = new Pictures(0.0f, 0.0f, D3DXVECTOR2(1.0f, 1.0f));
	if (!object[0]->initialize(graphics->device3d, "sprite\\skybackground.png", 1280, 720, 1, 1, true, D3DCOLOR_XRGB(0, 0, 0), 1.0f)) {
		MessageBox(NULL, "There was an issue creating the sprite", NULL, NULL);			//Device3d,sprite file name, width , height , row,collumn
		return initialize = false;
	}
	if (!object[1]->initialize(graphics->device3d, "sprite\\ben.png", 128, 192, 4, 4, true, D3DCOLOR_XRGB(0, 0, 0), 0.80f)) {
		MessageBox(NULL, "There was an issue creating the sprite", NULL, NULL);			//Device3d,sprite file name, width , height , row,collumn
		return initialize = false;
	}
	for (int i = 2; i < 9; i++) {
		object[i] = new Enemy(i*189.0f, 609.0f, D3DXVECTOR2(1.0f, 2.0f), 10, -15.0f, 5);
		if (!object[i]->initialize(graphics->device3d, "sprite\\pipestanding.png", 46, 111, 1, 1, true, D3DCOLOR_XRGB(0, 0, 0), 1.0f)) {
			MessageBox(NULL, "There was an issue creating the sprite", NULL, NULL);			//Device3d,sprite file name, width , height , row,collumn
			return initialize = false;
		}
	}
	for (int i = 9; i < 16; i++) {
		object[i] = new Enemy((i - 7)*189.0f, 0.0f, D3DXVECTOR2(1.0f, 1.5f), 10, -15.0f, 5);
		if (!object[i]->initialize(graphics->device3d, "sprite\\upsidedownPipe.png", 46, 114, 1, 1, true, D3DCOLOR_XRGB(0, 0, 0), 1.0f)) {
			MessageBox(NULL, "There was an issue creating the sprite", NULL, NULL);			//Device3d,sprite file name, width , height , row,collumn
			return initialize = false;
		}
	}

	//---------------------------------------------------------------------------------------------------------------------------------------------
	menuButton = new Button(0, 0, D3DXVECTOR2(1.0f, 1.0f), 30, "Main Menu", 10, 255, 155, 0, graphics->font);
	menuButton->setX(950);
	menuButton->setY(600);

	if (!menuButton->initialize(graphics->device3d, "sprite\\buttonTemplateAnimation.png", 1116, 76, 1, 4, true, D3DCOLOR_XRGB(255, 255, 255), 1.0f)) //Width, Height of the pic when printed in game, SpriteWidth, SpriteHeight, 
	{
		MessageBox(NULL, "There was an issue creating the menuButton", NULL, NULL);
		return initialize = false; //If false program wont run
	}
	childrenPointer = dynamic_cast<Button*>(menuButton);
	//---------------------------------------------------------------------------------------------------------------------------------------------
	srand(time(NULL));

	gravity = { 0,GRAVITY };
	object[1]->setState(3);

}

void FlappyBird::update(int gameTime)
{
	randomNumber = rand() % 3 + 1;
	if (childrenPointer->onHover(mouseX, mouseY))
	{
		if (childrenPointer->isClicked(input->leftClickDown))
		{
			state = GameStates::MENU;
			sound->fmodSystem->release();
		}
		menuButton->update(gameTime);
	}
	else {
		menuButton->setFrame(1);
	}

	for (int i = 0; i < FLAPPYBIRDOBJECTS; i++) {
		object[i]->update(gameTime);

	}
	if (counter == REQFPS) {
		timer++;
		counter = 0;
	}
	for (int i = 0; i < gameTime; i++) {
		counter++;
	}
	cursor->update(gameTime);
}

void FlappyBird::draw()
{
	graphics->clear(D3DCOLOR_XRGB(0, 100, 100));
	graphics->begin();
	object[0]->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	
	
	for (int i = 0; i < FLAPPYBIRDOBJECTS; i++) {
		object[i]->draw();
	}
	menuButton->draw();

	cursor->setMatrix(D3DXVECTOR2(1.0f, 1.0f), D3DXVECTOR2(0.0f, 0.0f), 0.0f, D3DXVECTOR2(GAME_WIDTH / 2, 25));		//Set this to draw my font
	graphics->drawfont("Seconds", timer, 10, 100, 100, cursor->sprite, D3DCOLOR_XRGB(255, 255, 255), 30);			// last parameter depends on the size of your font
	cursor->draw();
	object[0]->sprite->End();
	graphics->end();
	graphics->present();
}

void FlappyBird::collisions()
{

	object[1]->forceVector = { 0,0 };
	if (input->upArrowKey && !(object[1]->jump)) {
		object[1]->jump = true;
		object[1]->forceVector = { 0,-115 };
		std::cout << object[1]->forceVector.y << std::endl;
		std::cout << object[1]->jumpCD << std::endl;
	}

	object[1]->setAcceleration(object[1]->forceVector / object[1]->getMass());
	object[1]->setVelocity(object[1]->getVelocity() + object[1]->getAcceleration());
	if (object[1]->jumpCD >= 60 && input->upArrowKey) {
		object[1]->jump = false;
		object[1]->jumpCD = 0;
	}
	else {

		object[1]->setVelocity(D3DXVECTOR2(0, object[1]->getVelocityY()) + gravity);
	}
	
		for (int i = 0; i < FLAPPYBIRDOBJECTS; i++) {
			if (i == 1)i++;
			object[i]->setVelocity(D3DXVECTOR2(object[i]->getSpeed(), (timer+1.15*sin(object[i]->getObjectX()))));

		}
	
	object[5]->printData();
	for (int i = 2; i < FLAPPYBIRDOBJECTS; i++) {
		object[1]->enemyCollision = object[1]->collideWith(*object[i], object[1]->posVector);
		if (object[1]->enemyCollision) {
			std::cout << object[i]->getObjectX();
			object[1]->setStatus(ObjectStatus::Dead);
		}

	}
	if (object[1]->getStatus() == ObjectStatus::Dead) {
		sound->pauseMainMenuMusic();
		state = GameStates::LEVELPLAYERWIN;
	}


	if (object[1]->getVelocityY() < -50)
		std::cout << std::endl << object[1]->getVelocityY();
}

void FlappyBird::deleteAll()
{
	Game::deleteAll();
	for (int i = 0; i < FLAPPYBIRDOBJECTS; i++) {
		dltPtr(object[i]);
	}
}

FlappyBird::FlappyBird()
{

}


FlappyBird::~FlappyBird()
{
}
