#include "DXUT.h"
#include "cPlayer.h"

#include "cPlayerBullet.h"

cPlayer::cPlayer(vector<cBullet*>& playerBullet)
	:m_pos(WINSIZEX / 2, 450), m_fireBullet(playerBullet)
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
	if (GetAsyncKeyState(VK_SPACE) & 0x0001)
	{
		m_fireBullet.push_back(new cPlayerBullet(
			D3DXVECTOR2(m_pos.x, m_pos.y - 60)));
	}
}

void cPlayer::Render()
{
	m_playerImage->CenterRender(m_pos.x, m_pos.y);
}
