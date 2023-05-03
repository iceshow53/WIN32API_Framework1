#include "MainUpdate.h"
#include "Player.h"
#include "Enemy.h"


MainUpdate::MainUpdate() : m_pPlayer(NULL)
{
}

MainUpdate::~MainUpdate()
{
	Destroy();
}


void MainUpdate::Start()
{
	m_hdc = GetDC(g_hWnd);

	m_pPlayer = new Player();
	m_pPlayer->Start();

	m_Enemy = new Enemy();
	m_Enemy->Start();
}

void MainUpdate::Update()
{
	if(m_pPlayer)
		m_pPlayer->Update();
	if (m_Enemy)
		m_Enemy->Update();
}

void MainUpdate::Render()
{
	Rectangle(m_hdc, 0, 0, WIDTH, HEIGHT);

	if (m_pPlayer)
		m_pPlayer->Render(m_hdc);
	if (m_Enemy)
		m_Enemy->Render(m_hdc);
}

void MainUpdate::Destroy()
{
	if (m_pPlayer)
	{
		delete m_pPlayer;
		m_pPlayer = NULL;
	}

	if (m_Enemy)
	{
		delete m_Enemy;
		m_Enemy = NULL;
	}
}
