#include "DXUT.h"
#include "cPlayerBullet.h"

cPlayerBullet::cPlayerBullet(const D3DXVECTOR2& pos)
	:cBullet(pos, 20)
{
	m_image = IMAGEMANAGER->AddImage("playerBullet", "./image/playerBullet.png");
}

cPlayerBullet::~cPlayerBullet()
{
}

void cPlayerBullet::Update()
{
	m_pos.y -= 500 * DXUTGetElapsedTime();
}