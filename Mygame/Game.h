
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
#include "Platform.h"
#include "Enemy.h"
#include "Pictures.h"

class Game		//
{
protected:

	HWND hwnd;
	
	

	
	UserInterface *userinterface;
	Cursor *cursor;

	
	D3DXVECTOR2 friction;


public:
	int framesToUpdate;
	bool initialize;
	Graphics * graphics;
	GameTime *gameTime;
	PlayerInput *input;
	DxSound *sound;
	//Previously SetDrawingPoint function declaration was on this line.
	void run();
	void deletegraphics();
	virtual void deleteAll();
	virtual bool initializeGame(HWND hwnd);
	virtual void draw()=0;
	virtual void update(int gameTime) = 0;
	virtual void collisions()=0;
	int mouseX, mouseY;

	GameStates state;
	Game();
	~Game();
};

#endif // !GAME_H