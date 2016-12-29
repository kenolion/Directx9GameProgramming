#ifndef GAMETIME_H
#define GAMETIME_H
#include <Windows.h>
#include <iostream>

class GameTime
{
public:
	//float elapsedGameTime;
	//float totalGameTime;
	bool initialize(int);
	int update();
	GameTime();
	~GameTime();
	int Requested_FPS;
private:
//	LONGLONG start;
	//float frequencySeconds;
	LARGE_INTEGER timer_freq;
	LARGE_INTEGER time_now;
	LARGE_INTEGER time_previous;
	
	float intervalsPerFrame;
	
};

#endif // !GAMETIME_H
