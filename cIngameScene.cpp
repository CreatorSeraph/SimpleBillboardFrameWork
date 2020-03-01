#include "DXUT.h"
#include "cIngameScene.h"

#include "cScroolMap.h"
#include "cBulletAdmin.h"
#include "cPlayer.h"

cIngameScene::cIngameScene()
	//: m_map(nullptr), m_bullet(nullptr), m_player(nullptr)
{
	m_hpbar = IMAGEMANAGER->AddImage("hpbar", "./image/hpbar.png");
}


cIngameScene::~cIngameScene()
{
}

void cIngameScene::Init()
{
	OBJMANAGER->AddObject(new cScroolMap());
	OBJMANAGER->AddObject(new cPlayer());
	//m_map = new cScroolMap();
	//m_bullet = new cBulletAdmin();
	//m_player = new cPlayer(m_bullet->GetPlayerBullet());
}

void cIngameScene::Release()
{
	//SAFE_DELETE(m_map);
	//SAFE_DELETE(m_player);
	//SAFE_DELETE(m_bullet);
}

void cIngameScene::Update()
{
	//m_map->Update(100);
	//m_player->Update();
	//m_bullet->Update();
}

void cIngameScene::Render()
{
	//m_map->Render();
	//m_bullet->Render();
	//m_player->Render();
}

void cIngameScene::UIRender()
{
	UIMANAGER->Render(m_hpbar, 50, 50, 0.4, 0);
}
