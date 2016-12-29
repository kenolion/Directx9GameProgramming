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
	GameTime *time;
	Game *previousState;
	PlayerInput * playerinput;
	
	DxSound *sound;
	
	void initialize(HWND hwnd);
	void changeState(HWND hwnd);
	Graphics *graphic;
	FlappyBird *lvl1;
	LevelPlayerWins *pwin;
	LevelMainMenu *menu;

	GameStates state;
private:

};

#endif