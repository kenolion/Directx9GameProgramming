#ifndef FLAPPYBIRD_H
#define FLAPPYBIRD_H
#include "Game.h"
#include <time.h>
#include <math.h>

class FlappyBird:public Game
{
public:
	bool initializeGame(HWND hwnd);
	void update(int gameTime);
	void draw();
	void collisions();
	void deleteAll();
	int randomNumber;

	GameObject *object[FLAPPYBIRDOBJECTS];
	GameObject *menuButton;

	Button* childrenPointer;
	D3DXVECTOR2 gravity;

	int timer;				//increase by 1 each time count reaches the targeted fps
	int counter;			// used to count 1 second
	

	FlappyBird();
	~FlappyBird();
};

#endif // !FLAPPYBIRD_H