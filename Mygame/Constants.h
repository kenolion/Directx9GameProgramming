

#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <Windows.h>
const int GAME_WIDTH = 1280;
const int GAME_HEIGHT = 720;
const char CLASS_NAME[] = "Keith Class";
const char GAME_TITTLE[] = "MyFirstGame";


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