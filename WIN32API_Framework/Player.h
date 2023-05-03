#pragma once
#include "GameObject.h"

class Player : public GameObject
{
private:
	GameObject* BulletList[BULLETCOUNT];

public:
	virtual void Start()override;
	virtual void Start(Vector3 _position)override
	{
	};
	virtual int Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;
	virtual void ColTest(Vector3 _position)override;
public:
	GameObject* CreateBullet();
public:
	Player();
	virtual ~Player();
};

