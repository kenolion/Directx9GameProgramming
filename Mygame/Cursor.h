#ifndef CURSOR_H
#define CURSOR_H
#include "GameObject.h"

class Cursor : public GameObject
{
public:
	Cursor(float x, float y, D3DXVECTOR2 scaling);
	~Cursor();
	virtual void update(int &gameTime, D3DXVECTOR2 &position, D3DXVECTOR2 &force);

	
};

#endif