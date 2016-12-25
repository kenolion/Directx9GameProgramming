#ifndef BUTTON_H
#define BUTTON_H
#include "GameObject.h"
#include "Graphics.h"
#include "constants.h"
#include "PlayerInput.h"

#include<d3d9.h> 
#include<d3dx9.h>

class Button : public GameObject
{
public:

	LPD3DXFONT font = NULL; //P5 Font Pointer
	HRESULT hr;

	Button(float x, float y, D3DXVECTOR2 scaling, int animSpeed);

	void drawText(LPCSTR buttonText, int noOfChars, int r, int g, int b);

	void update(int &gameTime);
	~Button();

	bool initialize(LPDIRECT3DDEVICE9 device3d, std::string file, int width, int height, int row, int col, bool frameHorizontal, D3DXCOLOR color);
	bool onHover(int mouseX, int mouseY);

	RECT buttonRect;
	

	
};

#endif
