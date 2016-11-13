

#ifndef CONSTANTS_H
#define CONSTANTS_H

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

#endif // !CONSTANTS_H