#ifndef LEVELMAINMENU_H			//ZER ADD
#define LEVELMAINMENU_H

#include "Game.h"
#include "Graphics.h"
#include "GameSprite.h"
#include "GameObject.h"
#include "PlayerInput.h"
#include "Button.h"

class LevelMainMenu : public Game
{
public:

	GameObject * startButton;

	bool initializeGame(HWND hwnd);
	void update(int gameTime);
	void collisions();

	void draw();
	void deleteAll();

	LevelMainMenu();
	~LevelMainMenu();
};

#endif