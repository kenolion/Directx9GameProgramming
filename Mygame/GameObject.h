#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include "GameSprite.h"
#include <iostream>
#include "Constants.h"

enum class ObjectStatus { Active, Dying, Dead };

class GameObject
{
public:

	GameObject(float x, float y, float rotation, D3DXVECTOR2 scaling, float enginePower,int mass);													//
	GameObject(float x, float y, D3DXVECTOR2 scaling);		//Zer add

	~GameObject();
	virtual bool initialize(LPDIRECT3DDEVICE9 device3d, std::string file, int width, int height, int row, int col, bool frameHorizontal);
	virtual void update(int &gameTime, D3DXVECTOR2 &position, D3DXVECTOR2 &force) = 0;
	virtual void draw();

	ObjectStatus getStatus() const;
	//Sprite
	GameSprite *spriteClass;
	static LPD3DXSPRITE sprite;
	void setState(int state);
	float rotation;


	//physics
	void setAcceleration(D3DXVECTOR2 accel);
	void setVelocity(D3DXVECTOR2 vel);
	D3DXVECTOR2 getAcceleration();
	D3DXVECTOR2 getForce();
	D3DXVECTOR2 getVelocity();
	
	float getMass();
	bool collideWith(GameObject &object, D3DXVECTOR2 &collisionVector);
	float getSpeed();
	void setSpeed(float speed);
	D3DXVECTOR2 getObjectPos();
	bool collision;
	float enginePower;

	D3DXVECTOR2 distance;				//used for storing distance between objects in the collision function of gameobject

	
protected:
	//informational data(name, desc wtv u want)
	std::string name;
	std::string description;
	//physics data
	D3DXVECTOR2 position;
	D3DXVECTOR2 force;
	D3DXVECTOR2 velocity;
	D3DXVECTOR2 acceleration;
	D3DXVECTOR2 scaling;
	float mass;
	float speed;
	ObjectStatus status;

	D3DXVECTOR2 spriteCentre;
	D3DXMATRIX mat;

	//SPRITE INFO
	D3DXVECTOR2 radius;			//if theres any
	D3DCOLOR color;
	RECT spriteRect;
	int height;
	int width;
	int spriteRow;				// this int changes according to its sprite sheet
	int spriteCol;				//this int changes according to its sprite sheet
	int state;					// this variable changes according to the game loop
	int frame;					// this variable changes according to the game loop
	int spriteHeight;
	int spriteWidth;
	int maxFrame;
	bool frameHorizontal;
};

#endif // !GAMEOBJECT_H