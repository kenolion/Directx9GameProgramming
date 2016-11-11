
#ifndef GAME_H
#define GAME_H
#define _USE_MATH_DEFINES
#include <cmath>
#include "Graphics.h"
#include "constants.h"
#include "GameObject.h"
#include "GameTime.h"
#include "PlayerInput.h"
#include <iostream>

class Game
{
private:
	
	HWND hwnd;
	Graphics * graphics;
	GameObject *player;
	GameObject *player2;
	PlayerInput *pInput;
	GameTime *gameTime;
	PlayerInput *input;

public:
	int framesToUpdate;
	bool initialize;
	static void setDrawingPoint(int x, int y);
	void deleteAll();
	bool initializeGame(HWND hwnd);
	void run();
	void draw(float gameTime);
	void update(float gameTime);
	LRESULT messageHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	Game();
	~Game();
};

#endif // !GAME_H