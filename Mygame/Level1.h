#ifndef LEVEL1_H
#define LEVEL1_H

#include "Game.h"
class Level1:public Game
{
public:
	GameObject *player;
	GameObject *player2;
	bool initializeGame(HWND hwnd);
	void update(int gameTime);
	void collisions();
	void draw();
	void deleteAll();
	Level1();
	~Level1();
};

#endif // !LEVEL1_H
