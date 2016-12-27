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


	result = fmodSystem->createSound("sounds//clickSoundEffect.mp3", FMOD_DEFAULT, 0, &clickSound); //File name * Path, Behaviour of sound
	if (result != FMOD_OK) {
		MessageBox(NULL, "ERROR", "Could not load clickSoundEffect.mp3", MB_ICONERROR);
	}
	clickSound->setMode(FMOD_LOOP_OFF);  // No loop

	result = fmodSystem->createStream("sounds//mainMenuMusic.mp3", FMOD_DEFAULT, 0, &mainmenuMusic);
	if (result != FMOD_OK) {
		MessageBox(NULL, "ERROR", "Could not load mainMenuMusic.mp3", MB_ICONERROR);
	}
	mainmenuMusic->setMode(FMOD_LOOP_NORMAL);

	result = fmodSystem->createStream("sounds//playerWinMusic.mp3", FMOD_DEFAULT, 0, &playerWinMusic);
	if (result != FMOD_OK) {
		MessageBox(NULL, "ERROR", "Could not load playerWinMusic.mp3", MB_ICONERROR);
	}
	mainmenuMusic->setMode(FMOD_LOOP_NORMAL);


}

void DxSound::playMainMenuMusic()
{
	result = fmodSystem->playSound(FMOD_CHANNEL_FREE, mainmenuMusic, false, &channel);

}

void DxSound::playClickSound()
{
	result = fmodSystem->playSound(FMOD_CHANNEL_FREE, clickSound, false, &channel);
}

void DxSound::playPlayerWinMusic()
{
	result = fmodSystem->playSound(FMOD_CHANNEL_FREE, playerWinMusic, false, &channel);
}

void DxSound::pauseMainMenuMusic()
{
	result = fmodSystem->playSound(FMOD_CHANNEL_FREE, mainmenuMusic, true, &channel);
}

void DxSound::pausePlayerWinMusic()
{
	result = fmodSystem->playSound(FMOD_CHANNEL_FREE, playerWinMusic, true, &channel);
}

DxSound::DxSound()
{
}


DxSound::~DxSound()
{
}
