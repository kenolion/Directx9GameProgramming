#include "PlayerInput.h"



bool PlayerInput::initializeInput(HWND hwnd)		//Function that displays error message if play input is false
{

	HRESULT hr;

	hr = DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&DI_OBJECT, NULL);

	if (FAILED(hr)) {
		std::cout << "Failed to create Directinput object";
		system("pause");
		return false;
	}

	hr = DI_OBJECT->CreateDevice(GUID_SysKeyboard, &DI_Device, NULL);

	if (FAILED(hr)) {
		std::cout << "Failed to create directinput Device";
		system("pause");
		return false;
	}
	hr = DI_Device->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(hr)) {
		std::cout << "Failed to set data format";
		system("pause");
		return false;
	}
	hr = DI_Device->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	if (FAILED(hr)) {
		std::cout << "Failed to set cooperative level";
		system("pause");
		return false;
	}





	return true;

}

void PlayerInput::getInput()		//Function that gets the player input
{

	HRESULT hr;
	hr = DI_Device->Acquire();
	ZeroMemory(keys, sizeof(keys));
	DI_Device->GetDeviceState(sizeof(keys), (LPVOID)&keys);
	
	if (KEYDOWN(keys, leftAKey)) {
		leftArrowKey = true;
		keyPressed = true;
	}
	if (KEYDOWN(keys, rightAKey)) {
		rightArrowKey = true;
		keyPressed = true;
	}
	if (KEYDOWN(keys, upAKey)) {
		upArrowKey = true;
		keyPressed = true;
	}
	if (KEYDOWN(keys, downAKey)) {
		downArrowKey = true;
		keyPressed = true;

	}

	if (leftArrowKey == true && keys[leftAKey] ==0) {

		leftArrowKey = false;
		keyPressed = false;
	}
	if (rightArrowKey == true && keys[rightAKey] == 0) {

		rightArrowKey = false;
		keyPressed = false;
	}
	if (downArrowKey == true && keys[downAKey] == 0) {
		downArrowKey = false;
		keyPressed = false;
	}
	if (upArrowKey == true && keys[upAKey] == 0) {
		
		upArrowKey = false;
		keyPressed = false;
	}






}



PlayerInput::PlayerInput()		//Initialization of player input defailt values
{
	leftAKey = 203;
	rightAKey = 205;
	downAKey = 208;
	upAKey = 200;
}

//void PlayerInput::remapKeys()		
//{
//	HRESULT hr;
//
//	std::cout << "What key do you want to rebind?" << std::endl;
//
//	while (keys[59] != -1) {
//		
//		ZeroMemory(keys, sizeof(keys));
//		DI_Device->GetDeviceState(sizeof(keys), (LPVOID)&keys);
//		for (int a = 0; a < 256; a++) {
//			if (a == 59) {
//				a++;
//			}
//			if (keys[a] != 0) {
//				std::cout << a << ":" << keys[a] << std::endl;
//				tempRemapKey = a;
//				keys[59] = -1;
//			}
//
//
//
//		}
//	}
//	system("pause");
//	std::cout << "Enter another key"<<std::endl;
//	ZeroMemory(keys, sizeof(keys));
//	while (keys[59] != -1) {
//		hr = DI_Device->Acquire();
//		ZeroMemory(keys, sizeof(keys));
//		DI_Device->GetDeviceState(sizeof(keys), (LPVOID)&keys);
//		for (int a = 0; a < 256; a++) {
//			if (a == 59) {
//				a++;
//			}
//			if (keys[a] != 0) {
//				std::cout << a << ":" << keys[a] << std::endl;
//				if (tempRemapKey == leftAKey) {
//					leftAKey = a;
//				}
//				else if (tempRemapKey == rightAKey) {
//					rightAKey = a;
//				}
//				else if (tempRemapKey == upAKey) {
//					upAKey = a;
//				}
//				else if (tempRemapKey == rightAKey) {
//
//					rightAKey = a;
//				}
//
//				keys[59] = -1;
//
//			}
//
//
//
//		}
//	}
//
//}


PlayerInput::~PlayerInput()
{
	DI_Device->Unacquire();
	DI_Device->Release();
}
