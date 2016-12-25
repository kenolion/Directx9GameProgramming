#ifndef DXSOUND_H
#define DXSOUND_H

#ifndef NUM_CHANNELS
#define NUM_CHANNELS 3
#endif // !NUM_CHANNELS
#include <fmod.hpp>
#include <Windows.h>
class DxSound
{


public:
	FMOD::System *fmodSystem;
	FMOD_RESULT result;
	FMOD::Channel *channel;

	FMOD::Sound *soundtrack;

	bool initializeSound();
	void updateSound();
	void loadSounds();
	
	void playSoundtrack();



	DxSound();
	~DxSound();
};

#endif // !DXSOUND_H
