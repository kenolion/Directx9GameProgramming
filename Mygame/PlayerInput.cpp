#include "PlayerInput.h"



bool PlayerInput::initializeInput(HWND hwnd)
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

void PlayerInput::getInput()
{

	HRESULT hr;
	hr = DI_Device->Acquire();
	ZeroMemory(keys, sizeof(keys));
	DI_Device->GetDeviceState(sizeof(keys), (LPVOID)&keys);
	
	if (KEYDOWN(keys, leftAKey)) {
		std::cout << "Left arrow key was pressed!\n";
		leftArrowKey = true;

	}
	if (KEYDOWN(keys, rightAKey)) {
		std::cout << "right arrow key was pressed!\n";
		rightArrowKey = true;
	}
	if (KEYDOWN(keys, upAKey)) {
		std::cout << "up arrow key was pressed!\n";
		upArrowKey = true;
	}
	if (KEYDOWN(keys, downAKey)) {
		std::cout << "Down arrow key was pressed!\n";
		downArrowKey = true;

	}

	if (leftArrowKey == true && keys[leftAKey] ==0) {
		std::cout << "Left Arrow Key is released!" << std::endl;
		leftArrowKey = false;

	}
	if (rightArrowKey == true && keys[rightAKey] == 0) {
		std::cout << "right Key is released!" << std::endl;
		rightArrowKey = false;

	}
	if (downArrowKey == true && keys[downAKey] == 0) {
		std::cout << "Down Key is released!" << std::endl;
		downArrowKey = false;

	}
	if (upArrowKey == true && keys[upAKey] == 0) {
		std::cout << "up Key is released!" << std::endl;
		upArrowKey = false;

	}



	for (int a = 0; a < 256; a++) {
		if (keys[a] != 0)
			std::cout << a << ":" << keys[a] << std::endl;

	}



}



PlayerInput::PlayerInput()
{
	leftAKey = 203;
	rightAKey = 205;
	downAKey = 208;
	upAKey = 200;
}

void PlayerInput::remapKeys()
{
	HRESULT hr;

	std::cout << "What key do you want to rebind?" << std::endl;

	while (keys[59] != -1) {
		
		ZeroMemory(keys, sizeof(keys));
		DI_Device->GetDeviceState(sizeof(keys), (LPVOID)&keys);
		for (int a = 0; a < 256; a++) {
			if (a == 59) {
				a++;
			}
			if (keys[a] != 0) {
				std::cout << a << ":" << keys[a] << std::endl;
				tempRemapKey = a;
				keys[59] = -1;
			}



		}
	}
	system("pause");
	std::cout << "Enter another key"<<std::endl;
	ZeroMemory(keys, sizeof(keys));
	while (keys[59] != -1) {
		hr = DI_Device->Acquire();
		ZeroMemory(keys, sizeof(keys));
		DI_Device->GetDeviceState(sizeof(keys), (LPVOID)&keys);
		for (int a = 0; a < 256; a++) {
			if (a == 59) {
				a++;
			}
			if (keys[a] != 0) {
				std::cout << a << ":" << keys[a] << std::endl;
				if (tempRemapKey == leftAKey) {
					leftAKey = a;
				}
				else if (tempRemapKey == rightAKey) {
					rightAKey = a;
				}
				else if (tempRemapKey == upAKey) {
					upAKey = a;
				}
				else if (tempRemapKey == rightAKey) {

					rightAKey = a;
				}

				keys[59] = -1;

			}



		}
	}

}


PlayerInput::~PlayerInput()
{
	DI_Device->Unacquire();
	DI_Device->Release();
}
