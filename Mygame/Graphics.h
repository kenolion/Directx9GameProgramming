
#ifndef GRAPHICS_H
#define GRAPHICS_H
#define WIN32_LEAN_AND_MEAN
#include<d3d9.h> 
#include<d3dx9.h>
#include <Windows.h>
#include "Constants.h"
#include "GameSprite.h"
#define LP_TEXTURE  LPDIRECT3DTEXTURE9
#define LP_3DDEVICE LPDIRECT3DDEVICE9
#define LP_3D       LPDIRECT3D9

class Graphics
{
private:
	LP_3D direct3d;
	int width;
	int height;
public:
	LP_3DDEVICE device3d;

	HWND hwnd;
	HRESULT result;
	D3DPRESENT_PARAMETERS d3dpp;
	bool initialize(HWND hwnd,int w,int h);
	void clear(D3DCOLOR color);
	void begin();
	void end();
	void present();
	void cleanup();
	
	Graphics();
	~Graphics();
	
};


#endif // !DXGRAPHICS_H
