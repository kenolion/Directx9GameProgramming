
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
#include "DxSound.h"
#include "UserInterface.h"
#include "Cursor.h"
#include "Enemy.h"

class Game		//
{
protected:

	HWND hwnd;
	Graphics * graphics;
	GameTime *gameTime;
	PlayerInput *input;
	DxSound *sound;
	UserInterface *userinterface;
	Cursor *cursor;

	
	D3DXVECTOR2 friction;


public:
	int framesToUpdate;
	bool initialize;
	//Previously SetDrawingPoint function declaration was on this line.
	virtual void deleteAll();
	virtual bool initializeGame(HWND hwnd);
	void run();
	
	//================================================ State Changing Functions ================================================
	
	void changeState();
	void deleteSceneContents();

	//==========================================================================================================================

	virtual void draw()=0;
	virtual void update(int gameTime) = 0;
	virtual void collisions()=0;
	int mouseX, mouseY;
	LRESULT messageHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	Game();
	~Game();
};

#endif // !GAME_H