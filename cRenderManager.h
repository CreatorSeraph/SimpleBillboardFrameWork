#pragma once
#include "singleton.h"

class cTexture;
class cRenderManager : public singleton<cRenderManager>
{
private:
    struct sVertexType
    {
        D3DXVECTOR3 m_pos;
        D3DXVECTOR2 m_uv;

        inline static constexpr DWORD FVF = D3DFVF_XYZ | D3DFVF_TEX1;
    };
public:
    LPDIRECT3DVERTEXBUFFER9 m_vb;
    LPDIRECT3DINDEXBUFFER9 m_ib;
public:
    D3DXVECTOR3 m_camPos;
    D3DXVECTOR3 m_camLook;
    D3DXVECTOR3 m_camUp;
public:
    cRenderManager();
    ~cRenderManager();

    void CamUpdate();
    void Render(cTexture* texturePtr, float x, float y, float z = 0);
    void CenterRender(cTexture* texturePtr, float x, float y, float z = 0);
};

#define RENDER cRenderManager::GetInstance()