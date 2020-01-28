#pragma once
#include "singleton.h"

class cUIManager : public singleton<cUIManager>
{
private:
    LPD3DXSPRITE m_sprite;
public:
    cUIManager();
    ~cUIManager();
public:
    void Begin();
    void End();

    void LostDevice();
    void ResetDevice();

    void Render(cTexture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
    void Render(cTexture* texturePtr, float x, float y, float rot = 0);
    //�»���� �������� �̹��� ������

    void CenterRender(cTexture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
    void CenterRender(cTexture* texturePtr, float x, float y, float rot = 0);
    //����� �������� �̹��� ������
};

#define UIMANAGER cUIManager::GetInstance()