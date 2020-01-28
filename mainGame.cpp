#include "DXUT.h"
#include "mainGame.h"

#include "cIngameScene.h"

mainGame::mainGame()
{
}

mainGame::~mainGame()
{
}

void mainGame::Init()
{
	SCENEMANAGER->AddScene("ingame", new cIngameScene);

	SCENEMANAGER->ChangeScene("ingame");
}

void mainGame::Release()
{
	cImageManager::ReleaseInstance();
	cSceneManager::ReleaseInstance();
}

void mainGame::Update()
{
	SCENEMANAGER->Update();
}

void mainGame::Render()
{
	IMAGEMANAGER->Begin();

	SCENEMANAGER->Render();

	IMAGEMANAGER->End();
}

void mainGame::LostDevice()
{
}

void mainGame::ResetDevice()
{
}
