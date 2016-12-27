#include "GameStateManager.h"



GameStateManager::GameStateManager()
{
	game = &menu;
	
}


GameStateManager::~GameStateManager()
{
}

void GameStateManager::initialize(HWND hwnd)
{
	game->initializeGame(hwnd);
	state = GameStates::MENU;
	game->state = state;

}

void GameStateManager::changeState(HWND hwnd)
{
	if (game != NULL) {
		game->deleteAll();
	
		//dltPtr(game);

	}
	switch (state) {
	case GameStates::MENU:
		game = &menu;
		break;
	case GameStates::LEVEL1:
		game = &lvl1;
		break;
	case GameStates::LEVELPLAYERWIN:
		game = &pwin;



	}
	game->initializeGame(hwnd);
	game->state = state;


}

