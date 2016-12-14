#include "Graphics.h"




bool Graphics::initialize(HWND hw, int w, int h)
{
	hwnd = hw;
	width = w;
	height = h;
	//initialize direct3d
	direct3d = Direct3DCreate9(D3D_SDK_VERSION);
	if (direct3d == NULL) {
		::MessageBox(hwnd,
			"DirectX runtime library is not installed.",
			"System error", MB_ICONEXCLAMATION | MB_OK);
		return false;
	}
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	//Fil in some parameters
	d3dpp.BackBufferWidth = width;
	d3dpp.BackBufferHeight = height;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.BackBufferCount = 1;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = hwnd;
	d3dpp.Windowed = true;
	//d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	result = direct3d->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hwnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&device3d);

	return true;

}



void Graphics::clear(D3DCOLOR color)
{
	device3d->Clear(0, NULL, D3DCLEAR_TARGET,
		D3DCOLOR_XRGB(0, 100, 100), 1.0f, 0);  // 0x00000000 = black
	
}

void Graphics::begin()
{
	device3d->BeginScene();
}

void Graphics::end()
{
	// end scene
	device3d->EndScene();
}

void Graphics::present()
{
	device3d->Present(NULL, NULL, NULL, NULL);
}

void Graphics::cleanup()
{
	//
	// cleanup your objects here
	//

	if (device3d) {
		device3d->Release();
		device3d = NULL;
	}
	if (direct3d) {
		direct3d->Release();
		direct3d = NULL;
	}
}



Graphics::Graphics()
{
	device3d = NULL;
}


Graphics::~Graphics()
{
	if (device3d) {
		device3d->Release();
		device3d = NULL;
	}
	if (direct3d) {
		direct3d->Release();
		direct3d = NULL;
	}

}
