#include "Cursor.h"



Cursor::Cursor(float x, float y, D3DXVECTOR2 scaling):GameObject( x,  y, scaling)
{

}


Cursor::~Cursor()
{
}

void Cursor::update(int & gameTime, D3DXVECTOR2 & position, D3DXVECTOR2 & force)
{
	this->position = position;

}

