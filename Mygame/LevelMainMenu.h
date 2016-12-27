#ifndef LEVELMAINMENU_H			//ZER ADD
#define LEVELMAINMENU_H

#include "Game.h"

class LevelMainMenu : public Game
{
public:

	GameObject * startButton;
	GameObject * quitButton;
	GameObject * goombaOne;
	GameObject * backgroundImage;
	GameObject * gameLogo;

	//YOU DONT NEED A HITBOXLINE POINTER OBJECT, BECAUSE GRAPHICS IS ALREADY DECLARED	Graphics * hitBoxLines;

//	D3DXVECTOR2 goombaVector[];

	bool initializeGame(HWND hwnd);
	void update(int gameTime);
	void collisions();

	void draw();
	void deleteAll();

	LevelMainMenu();
	~LevelMainMenu();


	
		
};

#endif