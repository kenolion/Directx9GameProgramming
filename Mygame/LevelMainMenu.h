#ifndef LEVELMAINMENU_H			//ZER ADD
#define LEVELMAINMENU_H

#include "Game.h"
#include "Graphics.h"
class LevelMainMenu : public Game
{
public:
	bool initializeGame(HWND hwnd);
	void update(int gameTime);
	void collisions();

	void draw();
	void deleteAll();

	LevelMainMenu();
	~LevelMainMenu();
};

#endif