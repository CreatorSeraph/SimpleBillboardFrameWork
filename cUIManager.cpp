#include "DXUT.h"
#include "cUIManager.h"

cUIManager::cUIManager()
	: m_sprite(nullptr)
{
	D3DXCreateSprite(g_device, &m_sprite);
}

cUIManager::~cUIManager()
{
	m_sprite->Release();
}

void cUIManager::Begin()
{
	//D3DXMATRIXA16 matWorld;
	//D3DXMatrixIdentity(&matWorld);
	//g_device->SetTransform(D3DTS_WORLD, &matWorld);
	m_sprite->Begin(D3DXSPRITE_ALPHABLEND);
}

void cUIManager::End()
{
	m_sprite->End();
}

void cUIManager::Render(cTexture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color)
{
	if (texturePtr)
	{
		D3DXMATRIXA16 mat;

		D3DXMatrixAffineTransformation2D(&mat, size, nullptr, rot, &D3DXVECTOR2(x, y));
		m_sprite->SetTransform(&mat);
		m_sprite->Draw(texturePtr->texturePtr, nullptr, nullptr, nullptr, color);
	}
}

void cUIManager::Render(cTexture* texturePtr, float x, float y, float rot)
{
	if (texturePtr)
	{
		D3DXMATRIXA16 mat;

		D3DXMatrixAffineTransformation2D(&mat, 1.f, nullptr, rot, &D3DXVECTOR2(x, y));
		m_sprite->SetTransform(&mat);
		m_sprite->Draw(texturePtr->texturePtr, nullptr, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
	}
}

void cUIManager::CenterRender(cTexture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color)
{
	Render(texturePtr, x - texturePtr->info.Width / 2, y - texturePtr->info.Height / 2, size, rot, color);
}

void cUIManager::CenterRender(cTexture* texturePtr, float x, float y, float rot)
{
	Render(texturePtr, x - texturePtr->info.Width / 2, y - texturePtr->info.Height / 2, rot);
}

void cUIManager::LostDevice()
{
	m_sprite->OnLostDevice();
}

void cUIManager::ResetDevice()
{
	m_sprite->OnResetDevice();
}
