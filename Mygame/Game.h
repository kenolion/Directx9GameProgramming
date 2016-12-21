
#ifndef GAME_H
#define GAME_H
#define _USE_MATH_DEFINES
#include <cmath>
#include "Graphics.h"
#include "constants.h"
#include "GameObject.h"
#include "GameTime.h"
#include "PlayerInput.h"
#include "Player.h"
#include <iostream>

class Game		//
{
protected:

	HWND hwnd;
	Graphics * graphics;
	GameTime *gameTime;
	PlayerInput *input;
public:
	int framesToUpdate;
	bool initialize;
	static void setDrawingPoint(int x, int y);
	virtual void deleteAll();
	virtual bool initializeGame(HWND hwnd);
	void run();
	virtual void draw() = 0;
	virtual void update(int gameTime) = 0;
	
	LRESULT messageHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	Game();
	~Game();
};

#endif // !GAME_H