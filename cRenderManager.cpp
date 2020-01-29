#include "DXUT.h"
#include "cRenderManager.h"
#include "cTexture.h"

cRenderManager::cRenderManager()
{
    //빌보딩용 버퍼 생성
    g_device->CreateVertexBuffer(sizeof(sVertexType) * 4, D3DUSAGE_WRITEONLY, sVertexType::FVF, D3DPOOL_DEFAULT, &m_vb, NULL);

    sVertexType* pVertices = nullptr;

    m_vb->Lock(0, 0, (void**)&pVertices, 0);

    pVertices[0].m_pos = D3DXVECTOR3(-0.5f, 0.5f, 0.f);
    pVertices[1].m_pos = D3DXVECTOR3(0.5f, 0.5f, 0.f);
    pVertices[2].m_pos = D3DXVECTOR3(-0.5f, -0.5f, 0.f);
    pVertices[3].m_pos = D3DXVECTOR3(0.5f, -0.5f, 0.f);

    //0 1
    //
    //2 3

    pVertices[0].m_uv = D3DXVECTOR2(0, 0);
    pVertices[1].m_uv = D3DXVECTOR2(1, 0);
    pVertices[2].m_uv = D3DXVECTOR2(0, 1);
    pVertices[3].m_uv = D3DXVECTOR2(1, 1);

    m_vb->Unlock();

    g_device->CreateIndexBuffer(sizeof(WORD) * 6, D3DUSAGE_WRITEONLY, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &m_ib, NULL);

    WORD idx[] = { 1, 2, 0, 1, 3, 2 };

    void* pIndices = NULL;

    m_ib->Lock(0, 0, &pIndices, 0);
    memcpy(pIndices, idx, sizeof(WORD) * 6);
    m_ib->Unlock();
    //--빌보딩용 버퍼 생성

    //빌보딩용 버퍼 적용
    g_device->SetStreamSource(0, m_vb, 0, sizeof(sVertexType));
    g_device->SetFVF(sVertexType::FVF);
    g_device->SetIndices(m_ib);
    //--빌보딩용 버퍼 적용

    g_device->SetRenderState(D3DRS_LIGHTING, FALSE);
    g_device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
    g_device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
    g_device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
    //g_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

    //투영 행렬 적용
    D3DXMATRIXA16 matProj;

    D3DXMatrixOrthoRH(&matProj, WINSIZEX, WINSIZEY, 0, 100);
    g_device->SetTransform(D3DTS_PROJECTION, &matProj);
    //--투영 행렬 적용

    D3DXMATRIXA16 matView;
    m_camPos = D3DXVECTOR3(0.f, 0.f, 100.f);
    m_camLook = D3DXVECTOR3(0.f, 0.f, 0.f);
    m_camUp = D3DXVECTOR3(0.f, 1.f, 0.f);

    D3DXMatrixLookAtRH(&matView, &m_camPos, &m_camLook, &m_camUp);
    g_device->SetTransform(D3DTS_VIEW, &matView);
}

cRenderManager::~cRenderManager()
{
    m_ib->Release();
    m_vb->Release();
}

void cRenderManager::CamUpdate()
{
    D3DXMATRIXA16 matView;
    D3DXMatrixLookAtLH(&matView, &m_camPos, &m_camLook, &m_camUp);
    g_device->SetTransform(D3DTS_VIEW, &matView);
}

void cRenderManager::Render(cTexture* texturePtr, float x, float y, float z)
{
    D3DXMATRIXA16 matPos, matScale, matWorld;
    D3DXMatrixTranslation(&matPos, x - WINSIZEX / 2 + texturePtr->info.Width / 2, -(y - WINSIZEY / 2 + texturePtr->info.Height / 2), z);
    D3DXMatrixScaling(&matScale, texturePtr->info.Width, texturePtr->info.Height, 1);
    matWorld = matScale * matPos;

    g_device->SetTransform(D3DTS_WORLD, &matWorld);
    g_device->SetTexture(0, texturePtr->texturePtr);
    g_device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 4, 0, 2);
}

void cRenderManager::CenterRender(cTexture* texturePtr, float x, float y, float z)
{
    D3DXMATRIXA16 matPos, matScale, matWorld;
    D3DXMatrixTranslation(&matPos, x - WINSIZEX / 2, -(y - WINSIZEY / 2), z);
    D3DXMatrixScaling(&matScale, texturePtr->info.Width, texturePtr->info.Height, 1);
    matWorld = matScale * matPos;

    g_device->SetTransform(D3DTS_WORLD, &matWorld);
    g_device->SetTexture(0, texturePtr->texturePtr);
    g_device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 4, 0, 2);
}
