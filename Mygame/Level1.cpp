#include "Level1.h"



bool Level1::initializeGame(HWND hwnd)
{
	Game::initializeGame(hwnd);
	object[0] = new Player(50.0f, 100.0f, D3DXVECTOR2(1.0f, 1.0f), 10, 2, 5); //x, y, scaling, animation, speed,mass
	object[1] = new Player(200.0f, 50.0f, D3DXVECTOR2(1.0f, 1.0f), 2, 0, 5);//x, y, scaling, animation, speed,mass
	object[2] = new Platform(50.0f, 400.0f, D3DXVECTOR2(1.0f, 1.0f), 1);
	object[3] = new Platform(274.0f, 300.0f, D3DXVECTOR2(1.0f, 1.0f), 1);
	object[4] = new Platform(400.0f, 500.0f, D3DXVECTOR2(1.0f, 1.0f), 1);
	object[5] = new Enemy(1280.0f, 500.0f, D3DXVECTOR2(1.0f, 1.0f), 1, 2, 5);

	// initialize texture

	if (!object[0]->initialize(graphics->device3d, "sprite\\militia.png", 128, 192, 4, 4, true, D3DCOLOR_XRGB(0, 0, 0), 0.70f,0,0,0,0)) {
		MessageBox(NULL, "There was an issue creating the sprite", NULL, NULL);			//Device3d,sprite file name, width , height , row,collumn
		return initialize = false;
	}
	if (!object[1]->initialize(graphics->device3d, "sprite\\practical9.png", 64, 64, 2, 2, false, D3DCOLOR_XRGB(0, 0, 0), 0.70f,0,0,0,0)) {
		MessageBox(NULL, "There was an issue creating the sprite", NULL, NULL);
		return initialize = false;
	}
	if (!object[2]->initialize(graphics->device3d, "sprite\\smalldick.png", 224, 69, 1, 1, true, D3DCOLOR_XRGB(0, 0, 0), 1.0f,0,0,0,0)) {
		MessageBox(NULL, "There was an issue creating the sprite", NULL, NULL);
		return initialize = false;
	}
	if (!object[3]->initialize(graphics->device3d, "sprite\\smalldick.png", 224, 69, 1, 1, true, D3DCOLOR_XRGB(0, 0, 0), 1.0f,0,0,0,0)) {
		MessageBox(NULL, "There was an issue creating the sprite", NULL, NULL);
		return initialize = false;
	}
	if (!object[4]->initialize(graphics->device3d, "sprite\\smalldick.png", 224, 69, 1, 1, true, D3DCOLOR_XRGB(0, 0, 0), 1.0f,0,0,0,0)) {
		MessageBox(NULL, "There was an issue creating the sprite", NULL, NULL);
		return initialize = false;
	}
	if (!object[5]->initialize(graphics->device3d, "sprite\\goombawalkleft.png", 168, 31, 1, 8, true, D3DCOLOR_XRGB(0, 0, 0), 1.0f,0,0,0,0)) {
		MessageBox(NULL, "There was an issue creating the sprite", NULL, NULL);
		return initialize = false;
	}
	gravity = { 0,GRAVITY };
	friction = { FRICTION,0 };

	object[0]->setState(3);				//changes animaton state like walk left to walk right
	object[1]->setState(2);

	return true;
}

void Level1::update(int gameTime)
{
	for (int i = 0; i < GOBJECTNUML1; i++) {
		object[i]->update(gameTime);
	}



}

void Level1::collisions()
{

	//Collision should not update players position
	for (int i = 0; i < GOBJECTNUML1; i++) {
		object[i]->posVector = object[i]->getObjectPos();
		object[i]->printData();
	}

	//Player *p = dynamic_cast<Player*>(player);			//dynamic casting to access childrens variables
	if (input->rightArrowKey) {
		object[0]->forceVector = D3DXVECTOR2(object[0]->getSpeed(), 0);
		object[0]->setState(3);
	}
	if (input->leftArrowKey) {
		object[0]->forceVector = D3DXVECTOR2(-object[0]->getSpeed(), 0);
		object[0]->setState(2);
	}

	if (input->upArrowKey) {
		object[0]->forceVector = D3DXVECTOR2(0, -50);
		object[0]->setVelocity(D3DXVECTOR2(0, -0.01));

	}
	for (int i = 1; i < GOBJECTNUML1; i++) {
		object[i]->setAcceleration(object[i]->forceVector / object[i]->getMass());
		object[i]->setVelocity(object[i]->getVelocity() + object[i]->getAcceleration() + gravity);

	}
	if (input->keyPressed) {
		object[0]->setAcceleration(object[0]->forceVector / object[0]->getMass());
		object[0]->setVelocity(object[0]->getVelocity() + object[0]->getAcceleration());
	}





	object[0]->posVector += object[0]->getVelocity();
	for (int i = 1; i < GOBJECTNUML1; i++) {
		if (object[0]->collideWith(*object[i], object[0]->posVector)) {
			if (object[i]->getType() == ObjectType::Platform)		//2 is platform
				object[0]->platformCollision = true;
			if (object[i]->getType() == ObjectType::Player)		//2 is platform
				object[0]->enemyCollision = true;
			
		}
		else {
			if (object[i]->getType() == ObjectType::Player)		//2 is platform
				object[0]->enemyCollision = false;
			object[0]->platformCollision = false;
		}
	}

	for (int i = 0; i < GOBJECTNUML1; i++) {
		if (object[i]->getOnGroundStatus()) {

			object[i]->setVelocity(D3DXVECTOR2(object[i]->getVelocityX()*friction.x, 0));// applying friction
			std::cout << "Gravity off";

		}
		else {
			object[0]->setVelocity(object[0]->getVelocity() + gravity);
			//std::cout << "GRAVITY ON";
		}
	}
}

void Level1::draw()
{
	//Simple RGB value for background so use XRGB
	 //Draws sprite and other game object
	graphics->clear(D3DCOLOR_XRGB(0, 100, 100));
	graphics->begin();
	object[0]->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	for (int i = 0; i < GOBJECTNUML1; i++)
		object[i]->draw();


	object[0]->sprite->End();
	graphics->end();
	graphics->present();

}

void Level1::deleteAll()
{
	Game::deleteAll();
	for (int i = 0; i < GOBJECTNUML1; i++) {
		dltPtr(object[i]);
	}


}

Level1::Level1()
{
}


Level1::~Level1()
{

}


