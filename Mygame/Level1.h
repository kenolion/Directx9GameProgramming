#ifndef LEVEL1_H
#define LEVEL1_H

#include "Game.h"
#include <cmath>
class Level1:public Game
{
public:
	GameObject *object[GOBJECTNUML1];			//see constant header for GOBJECTNUML1 value
	bool initializeGame(HWND hwnd);
	void update(int gameTime);
	void collisions();
	void draw();
	void deleteAll();
	//sounds
	float pan;
	float frequency;
	D3DXVECTOR2 gravity;
	Level1();
	~Level1();
};

#endif // !LEVEL1_H
