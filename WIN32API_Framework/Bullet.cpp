#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::Start()
{
	transform.position = Vector3(0.0f, 0.0f, 0.0f);
	transform.rotation = Vector3(0.0f, 0.0f, 0.0f);
	transform.scale = Vector3(30.0f, 30.0f, 0.0f);

	Speed = 15.0f;
}

void Bullet::Start(Vector3 _position)
{
	transform.position = _position;
	transform.rotation = Vector3(0.0f, 0.0f, 0.0f);
	transform.scale = Vector3(30.0f, 30.0f, 0.0f);

	Speed = 15.0f;
}

int Bullet::Update()
{
	transform.position.x += Speed;

	if (transform.position.x > WIDTH)
		return 1;

	return 0;
}

void Bullet::Render(HDC hdc)
{
	Rectangle(hdc,
		int(transform.position.x - (transform.scale.x * 0.5f)),
		int(transform.position.y - (transform.scale.y * 0.5f)),
		int(transform.position.x + (transform.scale.x * 0.5f)),
		int(transform.position.y + (transform.scale.y * 0.5f)));
}

void Bullet::Destroy()
{
}

int Bullet::is_col(Vector3 _position)
{
	float x = transform.position.x - _position.x;
	float y = transform.position.y - _position.y;

	if (x / y <= 5)
		return 1;

	return 0;
}

