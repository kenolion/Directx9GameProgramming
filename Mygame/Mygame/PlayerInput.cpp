#include "PlayerInput.h"



bool PlayerInput::initializeInput(HWND hwnd)
{
	//rawinput[0].usUsagePage = 0x01;
	//rawinput[0].usUsage = 0x06; //mouse is 0x02
	//rawinput[0].dwFlags = 0;//tells how to intepret the device can be use to ignore hotkeys like windows key
	//rawinput[0].hwndTarget = 0;

	//if (RegisterRawInputDevices(rawinput, 1, sizeof(rawinput[0])) == FALSE) {
	//	return false;
	//}
	HRESULT hr;

	hr = DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8,(void**) &DI_OBJECT, NULL);

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
	
	if (KEYDOWN(keys, DIK_LEFT)) {
		std::cout << "Left arrow key was pressed!\n";
	}
	if (KEYDOWN(keys, DIK_RIGHT)) {
		std::cout << "right arrow key was pressed!\n";
	}
	if (KEYDOWN(keys, DIK_UP)) {
		std::cout << "up arrow key was pressed!\n";
	}
	if (KEYDOWN(keys, DIK_DOWN)) {
		std::cout << "Down arrow key was pressed!\n";
	}
}

PlayerInput::PlayerInput()
{
}


PlayerInput::~PlayerInput()
{
	DI_Device->Unacquire();
	DI_Device->Release();
}
