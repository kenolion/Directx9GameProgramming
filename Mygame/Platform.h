#ifndef Platform

#endif // !Platform
#include "GameObject.h"
class Platform:public GameObject
{
public:
	Platform(float x, float y, D3DXVECTOR2 scaling, int animSpeed);
	void update(int & gameTime);
	void draw();
	RECT playerCheck;
	~Platform();
};

