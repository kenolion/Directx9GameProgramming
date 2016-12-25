#include "GameObject.h"
LPD3DXSPRITE GameObject::sprite = NULL;
//Zer Add (For Button)
GameObject::GameObject(float x, float y, D3DXVECTOR2 scaling)
{
	position.x = x;
	position.y = y;
	this->scaling = scaling;
	color = D3DCOLOR_ARGB(255, 255, 255, 255);
	state = 1;			//Start it at frame 1
	frame = 1;
}

GameObject::GameObject()
{
}

GameObject::GameObject(float x, float y, D3DXVECTOR2 scaling, int animSpeed,float speed,int mass)
{
	position.x = x;
	position.y = y;
	this->scaling = scaling;
	//not mine
	/*if (rotation > twopi)
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
	velocity.y = sin(rotation) * speed;*/
	//
	this->speed = speed;
	color = D3DCOLOR_ARGB(255, 255, 255, 255);
	this->mass = mass;
	state = 1;			//Start it at frame 1
	frame = 1;
	this->animSpeed = animSpeed;
}


GameObject::~GameObject()
{
	if (sprite) {
		sprite->Release();
		sprite = 0;
	}
	delete spriteClass;
}

bool GameObject::initialize(LPDIRECT3DDEVICE9 device3d, std::string file, int width, int height, int row, int col, bool frameHorizontal, D3DXCOLOR color)
{
	status = ObjectStatus::Active;
	spriteClass = new GameSprite();
	// SPRITE IS EMPTY
	if (sprite == NULL) {
		HRESULT hr = D3DXCreateSprite(device3d, &sprite);
		if (FAILED(hr)) {
			MessageBox(NULL, "ERROR", "Could not create sprite", MB_ICONERROR);
			return false;
		}
	}
	this->frameHorizontal = frameHorizontal;
	spriteClass->initializeTex(device3d, file, width, height, row, col, color);  //When a game object is created, a game sprite is created.
	this->width = width;			//actual bitmap width
	this->height = height;			//actual bitmap height
	this->spriteRow = row;			//
	this->spriteCol = col;
	spriteHeight = height / spriteRow;
	spriteWidth = width / spriteCol;
	col_width = width * 0.70;
	col_height = height *0.70;
	col_xOffset = (width - col_width) / 2;
	col_yOffset = (height - col_height) / 2;

	//for rectangle collision
	
	if (frameHorizontal) {
		maxFrame = spriteCol;					//TEST CODE WILL BE CLEANED UP LATER

	}
	else {
		maxFrame = spriteRow;
	}


	return true;
}



void GameObject::draw()		//Function that draw sprite
{
	//for RECT collision
	left = position.x+col_xOffset;
	right = position.x + spriteWidth;
	top = position.y+col_yOffset;
	bottom = position.y + spriteHeight;

	if(frameHorizontal)
	{
	spriteRect.top = (state - 1)*spriteHeight;					
	spriteRect.bottom = spriteRect.top + spriteHeight;
	spriteRect.left = (frame - 1)*spriteWidth;
	spriteRect.right = spriteRect.left + spriteWidth;
	}
	else
	{
		spriteRect.top = (frame - 1)*spriteHeight;
		spriteRect.bottom = spriteRect.top + spriteHeight;
		spriteRect.left = (state - 1)*spriteWidth;
		spriteRect.right = spriteRect.left + spriteWidth;

		
	}
	
	spriteCentre = D3DXVECTOR2(spriteWidth / 2, spriteHeight / 2);
	D3DXMatrixTransformation2D(&mat, NULL, 0.0, &scaling, &spriteCentre, rotation, &position);
	sprite->SetTransform(&mat);
	if (sprite) 
	{
		spriteClass->draw(position, sprite, spriteRect, color);

	}

}

ObjectStatus GameObject::getStatus()
{
	return status;
}

void GameObject::setSpeed(float speed)		//Function to adjust the speed/velocity of the object
{
	this->speed = speed;
}

D3DXVECTOR2 GameObject::getObjectPos()
{
	return position;
}

float GameObject::getObjectX()
{
	return position.x;
}

float GameObject::getObjectY()
{
	return position.y;
}



float GameObject::getSpeed()
{
	return speed;
}

void GameObject::setState(int state)
{
	this->state = state;
}

bool GameObject::collideWith(GameObject &object,D3DXVECTOR2 &collisionVector)
{



	if (bottom < object.top)return false;
	if (top > object.bottom)return false;
	if (right < object.left)return false;
	if (left > object.right)return false;


	//distance = object.getObjectPos() - position;			// Distance = object2 position - object1 position		
	//
	//if (D3DXVec2Length(&distance) < (spriteCentre.x + object.spriteCentre.x)) {
	//	return true;
	//}


	//if (distance.y *distance.y + distance.x*distance.x < (spriteCentre.x + object.spriteCentre.x)*(spriteCentre.y + object.spriteCentre.y)) {			//it is squared to make value x and y positive if the player is on the right side of object or above object		
	//																																			// spritecentre = object radius
	//	return true;
	//}


	
	return true;
}


D3DXVECTOR2 GameObject::getAcceleration()
{
	return acceleration;
}

bool GameObject::getOnGroundStatus()
{
	return false;		// this function needs to be implemented if the object has an onground bool 
}


D3DXVECTOR2 GameObject::getVelocity()
{
	return velocity;
}

float GameObject::getVelocityX()
{
	return velocity.x;
}

float GameObject::getVelocityY()
{
	return velocity.y;
}

float GameObject::getMass()
{
	return mass;
}

void GameObject::setAcceleration(D3DXVECTOR2 accel)
{
	acceleration = accel;
}

void GameObject::setVelocity(D3DXVECTOR2 vel)
{
	velocity = vel;
}
