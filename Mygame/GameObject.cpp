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

GameObject::GameObject(float x, float y, float rotation, D3DXVECTOR2 scaling, float enginePower,int mass)
{
	float twopi = (float)(M_PI * 2);
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
	this->enginePower = enginePower;
	color = D3DCOLOR_ARGB(255, 255, 255, 255);
	this->mass = mass;
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
	spriteClass->initializeTex(device3d, file, width, height, row, col);  //When a game object is created, a game sprite is created.
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



void GameObject::draw()		//Function that draw sprite
{


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

ObjectStatus GameObject::getStatus() const
{
	return status;
}

void GameObject::setSpeed(float speed)		//Function to adjust the speed/velocity of the object
{
	/*if (speed >= 0 && speed <= maxSpeed) {
		this->speed = speed;
		velocity.x = cos(rotation) * speed;
		velocity.y = sin(rotation) * speed;
		velocity.z = 0;
	}*/
}

D3DXVECTOR2 GameObject::getObjectPos()
{
	return position;
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

	distance = object.getObjectPos() - position;			// Distance = object2 position - object1 position		
	
	if (D3DXVec2Length(&distance) < (spriteCentre.x + object.spriteCentre.x)) {
		return true;
	}
	//if (distance.y *distance.y + distance.x*distance.x < (spriteCentre.x + object.spriteCentre.x)*(spriteCentre.y + object.spriteCentre.y)) {			//it is squared to make value x and y positive if the player is on the right side of object or above object		
	//																																			// spritecentre = object radius
	//	return true;
	//}


	
	return false;
}

D3DXVECTOR2 GameObject::getAcceleration()
{
	return acceleration;
}

D3DXVECTOR2 GameObject::getForce()
{
	return force;
}

D3DXVECTOR2 GameObject::getVelocity()
{
	return velocity;
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
