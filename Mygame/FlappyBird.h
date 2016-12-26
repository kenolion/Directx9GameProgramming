#ifndef FLAPPYBIRD_H
#define FLAPPYBIRD_H
#include "Game.h"
class FlappyBird:public Game
{
public:
	bool initializeGame(HWND hwnd);
	void update(int gameTime);
	void draw();
	void collisions();
	void deleteAll();
	GameObject *object[FLAPPYBIRDOBJECTS];
	D3DXVECTOR2 gravity;

	FlappyBird();
	~FlappyBird();
};

#endif // !FLAPPYBIRD_H