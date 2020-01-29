#include "DXUT.h"
#include "cBullet.h"


cBullet::cBullet(const D3DXVECTOR2& pos, double size)
	: m_pos(pos), m_size(size), m_image(nullptr)
{
}


cBullet::~cBullet()
{
}

void cBullet::Render()
{
	RENDER->CenterRender(m_image, m_pos.x, m_pos.y);
}

bool cBullet::IsOutMap()
{
	return (m_pos.x - m_size < 0
		|| m_pos.x + m_size > WINSIZEX
		|| m_pos.y - m_size < 0
		|| m_pos.y + m_size > WINSIZEY);
}
