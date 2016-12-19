#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "constants.h"
#include "Graphics.h"
#include<d3d9.h> 
#include<d3dx9.h>

class UserInterface	
{
public:
	UserInterface();
	~UserInterface();

	void drawUIButton(LPD3DXLINE line, int x, int y, float startXA, float startYA, float startXB, float startYB, float startXC, float startYC, float startXD, float startYD);

	
};


#endif