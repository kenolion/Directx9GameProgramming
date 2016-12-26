#ifndef LEVELPLAYERWINS_H		//ZER ADD
#define LEVELPLAYERWINS_H
#include "Game.h"
class LevelPlayerWins: public Game
{
public:

	GameObject * returnToMainMenuButton;
	GameObject * backgroundImage;
	GameObject * youWinTextLogo;
	GameObject * quitButton;

	bool initializeGame(HWND hwnd);
	void update(int gameTime);
	void collisions();

	void draw();
	void deleteAll();

	LevelPlayerWins();
	~LevelPlayerWins();
};

#endif