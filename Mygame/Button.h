#ifndef BUTTON_H
#define BUTTON_H
#include "GameObject.h"
#include "Graphics.h"
#include "constants.h"
#include "PlayerInput.h"

#include <string>

#include<d3d9.h> 
#include<d3dx9.h>

class Button : public GameObject
{
public:
	Button(float x, float y, D3DXVECTOR2 scaling);

	~Button();

	void update(int &gameTime, D3DXVECTOR2 &position, D3DXVECTOR2 &force);

	void OnHover();
	

	
};

#endif
