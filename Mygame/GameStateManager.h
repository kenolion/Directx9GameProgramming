#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANGER_H


#include "LevelMainMenu.h"
#include "FlappyBird.h"
#include "LevelPlayerWins.h"

using namespace std;

class GameStateManager
{
public:
	GameStateManager();
	~GameStateManager();



	enum class GameStates			//Strongly Type enumartions may come in handy if this framework includes a level editor, other states that might have it's own main menu, exit enum and etcetera.
	{
		EXITPROGRAM,		//Array 0
		MENU,				//Array 1
		LEVEL1,				//Array 2
		LEVELPLAYERWIN		//Array 3
	};
	//gameStates is a type, so 

	//GameStates gameState = GameStates::MENU; //If you're using a strongly typed enumeration you must use a scope resolutions operator

	GameStates gameState;

	void run(enum gameState);


	bool initialize;

};	


#endif