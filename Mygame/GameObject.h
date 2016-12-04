#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include "GameSprite.h"
#include <iostream>

enum class ObjectStatus { Active, Dying, Dead };

class GameObject
{
public:

	GameObject(float x, float y, float rotation);
	~GameObject();
	virtual bool initialize(LPDIRECT3DDEVICE9 device3d, std::string file, int width, int height, int row, int col, bool frameHorizontal);
	virtual void update(int gameTime, bool keyPressed) =0;
	virtual void draw();

	ObjectStatus getStatus() const;
	void setSpeed(float speed);
	int getX();
	float getSpeed();
	GameSprite *spriteClass;
	static LPD3DXSPRITE sprite;
	void setState(int state);
	bool collideWith(GameObject &object);
	bool collision;

	//physics
	D3DXVECTOR3 getAcceleration();
	void setAcceleration(D3DXVECTOR3 accel);

protected:
	//informational data(name, desc wtv u want)
	std::string name;
	std::string description;
	//physics data
	D3DXVECTOR3 position;
	D3DXVECTOR3 velocity;
	D3DXVECTOR3 acceleration;
	D3DXVECTOR2 scaling;
	float rotation;
	float speed;
	ObjectStatus status;
	

	//SPRITE INFO

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