#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANGER_H
#include "Game.h"
#include "LevelMainMenu.h"
#include"LevelPlayerWins.h"
#include "FlappyBird.h"
class GameStateManager
{
public:
	GameStateManager();
	~GameStateManager();

	Game * game;
	
	void initialize(HWND hwnd);
	void changeState(HWND hwnd);

	FlappyBird lvl1;
	LevelPlayerWins pwin;
	LevelMainMenu menu;

	GameStates state;
private:

};

#endif