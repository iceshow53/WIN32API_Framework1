#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::Start()
{
}

void Bullet::Start(Vector3 _position)
{
	transform.position = _position;
	transform.rotation = Vector3(0.0f, 0.0f, 0.0f);
	transform.scale = Vector3(30.0f, 30.0f, 0.0f);

	Speed = 15.0f;

	Key = "Bullet";
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
	Ellipse(hdc,
		int(transform.position.x - (transform.scale.x * 0.5f)),
		int(transform.position.y - (transform.scale.y * 0.5f)),
		int(transform.position.x + (transform.scale.x * 0.5f)),
		int(transform.position.y + (transform.scale.y * 0.5f)));
}

void Bullet::Destroy()
{
}

