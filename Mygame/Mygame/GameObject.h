#ifndef GAMEOBJECT_H


#define GAMEOBJECT_H
#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include "GameSprite.h"

enum class ObjectStatus { Active, Dying, Dead };

class GameObject
{
public:

	GameObject(float x, float y, float rotation, float speed, float maxSpeed);
	~GameObject();
	virtual bool initialize(LPDIRECT3DDEVICE9 device3d, std::string file, int width, int height);
	virtual void update(float gameTime);
	virtual void draw(float gameTime);

	ObjectStatus getStatus() const;
	void setSpeed(float speed);
	int getX();

protected:
	//informational data(name, desc wtv u want)
	std::string name;
	std::string description;
	//physics data
	D3DXVECTOR3 position;
	D3DXVECTOR3 velocity;
	D3DXVECTOR2 trans;
	D3DXMATRIX mat;

	D3DXVECTOR2 scaling;
	float rotation;
	float speed;

private:
	ObjectStatus status;
	GameSprite* sprite;
	float maxSpeed;

};

#endif // !GAMEOBJECT_H