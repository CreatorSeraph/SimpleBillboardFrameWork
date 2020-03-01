#include "DXUT.h"
#include "cPlayer.h"

#include "cPlayerBullet.h"

cPlayer::cPlayer()
	:m_pos(WINSIZEX / 2, 450)
{
	m_playerImage = IMAGEMANAGER->AddImage("player", "./image/player.png");
}


cPlayer::~cPlayer()
{
}

void cPlayer::Update()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		m_pos.x -= 300 * DXUTGetElapsedTime();
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		m_pos.x += 300 * DXUTGetElapsedTime();
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		m_pos.y -= 300 * DXUTGetElapsedTime();
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		m_pos.y += 300 * DXUTGetElapsedTime();
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		OBJMANAGER->AddObject(new cPlayerBullet(D3DXVECTOR2(m_pos.x, m_pos.y - 60)));
	}
}

void cPlayer::Render()
{
	cout << m_pos.x << "\t" << m_pos.y << endl;
	RENDER->CenterRender(m_playerImage, m_pos.x, m_pos.y, 1);
}
