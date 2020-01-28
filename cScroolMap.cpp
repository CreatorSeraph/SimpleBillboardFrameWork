#include "DXUT.h"
#include "cScroolMap.h"


cScroolMap::cScroolMap()
	:m_scrool(0)
{
	m_backGround = IMAGEMANAGER->AddImage("mapBackGround", "./image/mapBackGround.png");
}

cScroolMap::~cScroolMap()
{
}

void cScroolMap::Update(float speed)
{
	m_scrool += speed * DXUTGetElapsedTime();
}

void cScroolMap::Render()
{
	//반복되는 백그라운드 이미지를 예시로 사용할것임
	float renderPos = (int)m_scrool % m_backGround->info.Height;
	UIMANAGER->Render(m_backGround, 0, renderPos - m_backGround->info.Height);
	UIMANAGER->Render(m_backGround, 0, renderPos);
}
