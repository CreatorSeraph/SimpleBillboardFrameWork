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
	cUIManager::ReleaseInstance();
}

void mainGame::Update()
{
	SCENEMANAGER->Update();
}

void mainGame::Render()
{
	UIMANAGER->Begin();

	SCENEMANAGER->Render();

	UIMANAGER->End();
}

void mainGame::LostDevice()
{
	UIMANAGER->LostDevice();
}

void mainGame::ResetDevice()
{
	UIMANAGER->ResetDevice();
}
