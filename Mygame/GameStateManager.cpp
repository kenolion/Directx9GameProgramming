#include "GameStateManager.h"



GameStateManager::GameStateManager()
{
	game = new LevelMainMenu();

	
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
		//previousState = game;
		sound = game->sound;
		graphic = game->graphics;
		time = game->gameTime;
		playerinput = game->input;
		game->deleteAll();
		//dltPtr(game);

	}
	
	switch (state) {
	case GameStates::MENU:
		//game = &menu;
		game = new LevelMainMenu();
		break;
	case GameStates::LEVEL1:
		//game = &lvl1;
		game = new FlappyBird();
		break;
	case GameStates::LEVELPLAYERWIN:
		//game = &pwin;
		game = new LevelPlayerWins();


	}

	game->graphics = graphic;
	game->gameTime = time;
	game->input = playerinput;
	game->sound = sound;

	game->initializeGame(hwnd);
	game->state = state;


}


