#include "GameObject.h"


GameObject::GameObject(float x, float y, float rotation, float speed, float maxSpeed)
{
	float twopi = (float)(M_PI * 2);
	position.x = x;
	position.y = y;
	position.z = 0;

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
}


GameObject::~GameObject()
{
	if (sprite) {
		delete sprite;
		sprite = 0;
	}
}

bool GameObject::initialize(LPDIRECT3DDEVICE9 device3d, std::string file, int width, int height, int row, int col)
{
	status = ObjectStatus::Active;

	if (!sprite) {
		sprite = new GameSprite();
		if (!sprite->initialize(device3d, file, width, height, row, col)) {
			return false;
		}
	}

	return true;
}

void GameObject::update(int gameTime)
{
	if (status == ObjectStatus::Active) {
		for (int i = 0; i < gameTime; i++) {
			//position.x += velocity.x;
			//position.y += velocity.y;
			sprite->updateFrame();



			position.z = 0;// not important
			if (velocity.x > 0)
				velocity.x -= 0.1;
			if (velocity.y > 0)
				velocity.y -= 0.1;
		}
	}

}

void GameObject::draw(int gameTime)
{
	if (sprite) {
		sprite->draw(gameTime, position);
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
