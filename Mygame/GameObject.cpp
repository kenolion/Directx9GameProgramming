#include "GameObject.h"
LPD3DXSPRITE GameObject::sprite = NULL;

GameObject::GameObject(float x, float y, float rotation, float speed, float maxSpeed)
{
	float twopi = (float)(M_PI * 2);
	position.x = x;
	position.y = y;
	position.z = 0;
	//not mine
	if (rotation > twopi)
		rotation = twopi;
	if (rotation < 0)
		rotation = 0;
	if (speed > maxSpeed)
		speed = maxSpeed;
	if (speed < 0)
		speed = 0;
	this->rotation = rotation;
	this->speed = speed;
	velocity.x = cos(rotation) * speed;
	velocity.y = sin(rotation) * speed;
	velocity.z = 0;
	this->maxSpeed = maxSpeed;
	//

	color = D3DCOLOR_ARGB(255, 255, 255, 255);

	state = 1;			//Start it at frame 1
	frame = 1;
}


GameObject::~GameObject()
{
	if (sprite) {
		sprite->Release();
		sprite = 0;
	}
	delete spriteClass;
}

bool GameObject::initialize(LPDIRECT3DDEVICE9 device3d, std::string file, int width, int height, int row, int col, bool frameHorizontal)
{
	status = ObjectStatus::Active;
	spriteClass = new GameSprite();
	// SPRITE IS EMPTY
	if (sprite == NULL) {
		HRESULT hr = D3DXCreateSprite(device3d, &sprite);
		if (FAILED(hr)) {
			std::cout << "Error creating sprite";
			system("pause");
		}
	}
	this->frameHorizontal = frameHorizontal;

	spriteClass->initializeTex(device3d, file, width, height, row, col);
	this->width = width;
	this->height = height;
	this->spriteRow = row;
	this->spriteCol = col;
	spriteHeight = height / spriteRow;
	spriteWidth = width / spriteCol;
	if (frameHorizontal) {
		maxFrame = spriteCol;					//TEST CODE WILL BE CLEANED UP LATER

	}
	else {
		maxFrame = spriteRow;

	}


	return true;
}



void GameObject::draw()
{
	if(frameHorizontal)
	{
	spriteRect.top = (state - 1)*spriteHeight;
	spriteRect.bottom = spriteRect.top + spriteHeight;
	spriteRect.left = (frame - 1)*spriteWidth;
	spriteRect.right = spriteRect.left + spriteHeight;
	}
	else
	{
		spriteRect.top = (frame - 1)*spriteHeight;
		spriteRect.bottom = spriteRect.top + spriteHeight;
		spriteRect.left = (state - 1)*spriteWidth;
		spriteRect.right = spriteRect.left + spriteHeight;
	}
	if (sprite) 
	{
		spriteClass->draw(position, sprite, spriteRect, color);

	}

}

ObjectStatus GameObject::getStatus() const
{
	return status;
}

void GameObject::setSpeed(float speed)
{
	if (speed >= 0 && speed <= maxSpeed) {
		this->speed = speed;
		velocity.x = cos(rotation) * speed;
		velocity.y = sin(rotation) * speed;
		velocity.z = 0;
	}
}

int GameObject::getX()
{
	return position.x;
}

float GameObject::getSpeed()
{
	return speed;
}

void GameObject::setState(int state)
{
	this->state = state;
}
