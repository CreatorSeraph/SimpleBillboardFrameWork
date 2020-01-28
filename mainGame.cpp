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
	cSceneManager::ReleaseInstance();
	cUIManager::ReleaseInstance();
	cRenderManager::ReleaseInstance();
	cImageManager::ReleaseInstance();
}

void mainGame::Update()
{
	SCENEMANAGER->Update();
}

void mainGame::Render()
{
	SCENEMANAGER->Render();

	UIMANAGER->Begin();

	SCENEMANAGER->UIRender();

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
