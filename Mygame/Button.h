#ifndef BUTTON_H
#define BUTTON_H
#include "UserInterface.h"

class Button : public UserInterface
{
public:
	Button();
	~Button();

	void OnHover();
	void drawOn(int x, int y);
};

#endif
