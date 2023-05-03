#include "Enemy.h"
Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Start()
{
	srand((unsigned int)GetTickCount64());
	transform.position = Vector3(WIDTH + 60.0f, float(rand() % (HEIGHT - 120) + 60), 0.0f);
	transform.rotation = Vector3(0.0f, 0.0f, 0.0f);
	transform.scale = Vector3(120.0f, 120.0f, 0.0f);

	Speed = 0.5f;
}

int Enemy::Update()
{
	transform.position.x -= Speed;

	if (transform.position.x < 0)
		return 2;
	
    return 0;
}

void Enemy::Render(HDC hdc)
{
	Ellipse(hdc,
		int(transform.position.x - (transform.scale.x * 0.5f)),
		int(transform.position.y - (transform.scale.y * 0.5f)),
		int(transform.position.x + (transform.scale.x * 0.5f)),
		int(transform.position.y + (transform.scale.y * 0.5f)));

	//hbrBkgnd = CreateSolidBrush(RGB(255, 30, 120));

	//rect = { int(transform.position.x - (transform.scale.x * 0.5f)),
	//	int(transform.position.y - (transform.scale.y * 0.5f)),
	//	int(transform.position.x + (transform.scale.x * 0.5f)),
	//	int(transform.position.y + (transform.scale.y * 0.5f)) };

	//FillRect(hdc, &rect, hbrBkgnd);
}

void Enemy::Destroy()
{
}

