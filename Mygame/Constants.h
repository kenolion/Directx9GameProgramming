

#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <Windows.h>
const int GAME_WIDTH = 800;
const int GAME_HEIGHT = 600;
const char CLASS_NAME[] = "Keith Class";
const char GAME_TITTLE[] = "MyFirstGame";

const int GROUND_LEVEL = GAME_HEIGHT - 150;		// sets the height of ground 150 pixels
const float GRAVITY = 0.5;
const float FRICTION = 0.97;
const float PLAYERMAXVEL = 1;

//LEVEL1
const int GOBJECTNUML1 = 2;


template<typename T>
inline void dltPtr(T& ptr) {
	if (ptr){
		delete ptr;
		ptr = NULL;
	}

}

static void setDrawingPoint(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

#endif // !CONSTANTS_H