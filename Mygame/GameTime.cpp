#include "GameTime.h"


bool GameTime::initialize(int fps)
{
	////LARGE_INTEGER i;
	//////get frequency from counter
	////if (!QueryPerformanceFrequency(&i)) {
	////	return false;
	////}

	//////gives us the nuibmer of ticks per second
	////frequencySeconds = (float)(i.QuadPart);
	//////gets the current value of counter
	////QueryPerformanceCounter(&i);
	////start = i.QuadPart;
	////totalGameTime = 0;
	////elapsedGameTime = 0; 
	QueryPerformanceFrequency(&timer_freq);
	QueryPerformanceCounter(&time_now);
	QueryPerformanceCounter(&time_previous);
	Requested_FPS = fps;
	intervalsPerFrame = ((float)timer_freq.QuadPart / Requested_FPS);
	return true;
}

int GameTime::update()
{
	int framesToUpdate = 0;
	float intervalSinceLastUpdate;
	QueryPerformanceCounter(&time_now);
	intervalSinceLastUpdate = (float)time_now.QuadPart - (float)time_previous.QuadPart;

	framesToUpdate = (int)(intervalSinceLastUpdate / intervalsPerFrame);
	if (framesToUpdate != 0) {
		QueryPerformanceCounter(&time_previous);
		
	}
	/*LARGE_INTEGER i;
	QueryPerformanceCounter(&i);
	std::cout << (i.QuadPart-start)/30 <<"\n";
	elapsedGameTime = (float)(i.QuadPart - start) / frequencySeconds;
	start = i.QuadPart;
	totalGameTime += elapsedGameTime;*/
	return framesToUpdate;
}

GameTime::GameTime()
{
}


GameTime::~GameTime()
{
}
