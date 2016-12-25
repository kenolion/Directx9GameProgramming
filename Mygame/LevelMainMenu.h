#ifndef LEVELMAINMENU_H			//ZER ADD
#define LEVELMAINMENU_H

#include "Game.h"

class LevelMainMenu : public Game
{
public:

	GameObject * startButton;
	GameObject * quitButton;
	GameObject * goombaOne;
	GameObject * backgroundImage;
	GameObject * gameLogo;

	bool initializeGame(HWND hwnd);
	void update(int gameTime);
	void collisions();

	void draw();
	void deleteAll();

	LevelMainMenu();
	~LevelMainMenu();


	
		
};

#endif