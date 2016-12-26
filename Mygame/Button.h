#ifndef BUTTON_H
#define BUTTON_H
#include "GameObject.h"


class Button : public GameObject
{
public:

	//D3DX VARIABLES
	LPD3DXFONT font = NULL; //P5 Font Pointer
	HRESULT hr;

	//VARIABLES
	RECT buttonRect;				//Hitbox for the Button
	LPCSTR string;					//Text for the Button
	int noOfCharacters;				//Number of Characters of the text on the button
	int r, g, b;					//RGB colour to mainpulate the colour of the button.


	//FUNCTIONS
	Button(float x, float y, D3DXVECTOR2 scaling, int animSpeed, LPCSTR string,int noOfCharacters,int r, int g, int b);

	void draw();
	void update(int &gameTime);

	~Button();

	bool initialize(LPDIRECT3DDEVICE9 device3d, std::string file, int width, int height, int row, int col, bool frameHorizontal, D3DXCOLOR color, float falseColl, float hitBoxTop, float hitBoxBottom, float hitBoxLeft, float hitBoxRight);
	bool onHover(int mouseX, int mouseY);
	bool isClicked(bool leftClickDown);


	

	
};

#endif
