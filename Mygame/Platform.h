#ifndef PLATFORM_H
#define PLATFORM_H
#include "GameObject.h"

class Platform:public GameObject
{
public:

	void draw();
	void update();
	Platform();
	~Platform();
};

#endif // PLATFORM_H