

#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <Windows.h>
const int GAME_WIDTH = 800;
const int GAME_HEIGHT = 600;
const char CLASS_NAME[] = "Keith Class";
const char GAME_TITTLE[] = "MyFirstGame";


template<typename T>
inline void dltPtr(T& ptr) {
	if (ptr){
		delete ptr;
		ptr = NULL;
	}



}

void setDrawingPoint(int x, int y)
{
	COORD coord; //Does not need to be define because if we right click COORD and go to definition it is already defined in another library
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

static void setDrawingPoint(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

#endif // !CONSTANTS_H