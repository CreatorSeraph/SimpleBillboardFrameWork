#pragma once
#include "cObject.h"

class cBullet abstract : public cObject
{
protected:
	cTexture* m_image;
	D3DXVECTOR2 m_pos;

	double m_size;
public:
	cBullet(const D3DXVECTOR2& pos, double size);
	virtual ~cBullet();

	virtual void Update() override;
	virtual void Render() override;

	bool IsOutMap();
};