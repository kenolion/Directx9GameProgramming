#include "DxSound.h"



bool DxSound::initializeSound()
{
	result = FMOD::System_Create(&fmodSystem);
	if (result != FMOD_OK) {
		MessageBox(NULL, "ERROR", "Could not create fmodsystem!", MB_ICONERROR);
		return false;

	}

	result = fmodSystem->init(NUM_CHANNELS, FMOD_INIT_NORMAL, 0);
	if (result != FMOD_OK) {
		MessageBox(NULL, "ERROR", "Could not initiaize fmodsystem!", MB_ICONERROR);
		return false;
	}

}

void DxSound::updateSound()
{
	result = fmodSystem->update();

	if (result != FMOD_OK) {
		MessageBox(NULL, "ERROR", "Could not update fmod!", MB_ICONERROR);
	}
}

void DxSound::loadSounds()
{
	result = fmodSystem->createStream("Music1.mp3", FMOD_DEFAULT, 0, &soundtrack);

	if (result != FMOD_OK) {
		MessageBox(NULL, "ERROR", "Could not load Music1.mp3", MB_ICONERROR);
	}
	soundtrack->setMode(FMOD_LOOP_NORMAL);


}

void DxSound::playSoundtrack()
{
	result = fmodSystem->playSound(FMOD_CHANNEL_FREE, soundtrack, false, &channel);

}

DxSound::DxSound()
{
}


DxSound::~DxSound()
{
}
