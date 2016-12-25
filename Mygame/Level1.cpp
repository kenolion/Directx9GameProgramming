#include "Level1.h"



bool Level1::initializeGame(HWND hwnd)
{
	Game::initializeGame(hwnd);
	object[0] = new Player(50.0f, 50.0f, D3DXVECTOR2(1.0f, 1.0f), 10, 2, 5); //x, y, scaling, animation, speed,mass
	object[1] = new Player(600.0f, 50.0f, D3DXVECTOR2(1.0f, 1.0f), 2, 0, 5);//x, y, scaling, animation, speed,mass

	// initialize texture
	if (!object[0]->initialize(graphics->device3d, "sprite\\militia.png", 128, 192, 4, 4, true)) {
		MessageBox(NULL, "There was an issue creating the sprite", NULL, NULL);			//Device3d,sprite file name, width , height , row,collumn
		return initialize = false;
	}
	if (!object[1]->initialize(graphics->device3d, "sprite\\practical9.png", 64, 64, 2, 2, false)) {
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
	for (int i = 0; i<GOBJECTNUML1; i++) {
		object[i]->posVector = object[i]->getObjectPos();
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
	}
	for(int i = 1;i<GOBJECTNUML1;i++){
		object[i]->setAcceleration(object[i]->forceVector / object[i]->getMass());
		object[i]->setVelocity(object[i]->getVelocity() + object[i]->getAcceleration()+gravity);

	}
	if (input->keyPressed) {
		object[0]->setAcceleration(object[0]->forceVector / object[0]->getMass());
		object[0]->setVelocity(object[0]->getVelocity() + object[0]->getAcceleration());
	}
	if (object[0]->getOnGroundStatus()) {
		object[0]->setVelocity(D3DXVECTOR2(object[0]->getVelocityX()*friction.x, object[0]->getVelocityY()));// applying friction
		if (abs(object[0]->getVelocityX()) < 0.3) {
			object[0]->setVelocity(D3DXVECTOR2(0,object[0]->getVelocityY()));
		}
	}
	else {
		object[0]->setVelocity(object[0]->getVelocity() + gravity);
	}
	
	object[0]->collision = object[0]->collideWith(*object[1], object[0]->posVector);

	
}

void Level1::draw()
{
	//Simple RGB value for background so use XRGB
	 //Draws sprite and other game object
	graphics->clear(D3DCOLOR_XRGB(0, 100, 100));
	graphics->begin();
	for(int i = 0;i<GOBJECTNUML1;i++)
		object[i]->draw();

	

	graphics->end();
	graphics->present();

}

void Level1::deleteAll()
{
	Game::deleteAll();
	for(int i =0; i <GOBJECTNUML1;i++){
	dltPtr(object[i]);
	}


}

Level1::Level1()
{
}


Level1::~Level1()
{

}


