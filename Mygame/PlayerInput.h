#ifndef PLAYERINPUT_H
#define PLAYERINPUT_H
#include <d3d9.h>
#define DIRECTINPUT_VERSION 0x0800

#include <dinput.h>
#define KEYDOWN(name, key) (name[key] & 0x80)
//#define DIK_LEFT 0x1F
#include <iostream>
class PlayerInput
{
public:

	LPDIRECTINPUT8 DI_OBJECT;
	LPDIRECTINPUTDEVICE8 DI_Device;
	//RAWINPUTDEVICE rawinput[1];
	bool initializeInput( HWND hwnd);
	char keys[256];
	void getInput();
	int leftAKey;
	int rightAKey;
	int downAKey;
	int upAKey;
	int tempRemapKey;
	PlayerInput();
	void remapKeys();
	bool upArrowKey;
	bool downArrowKey;
	bool rightArrowKey;
	bool leftArrowKey;

	bool keyPressed;


	~PlayerInput();
	
};

#endif