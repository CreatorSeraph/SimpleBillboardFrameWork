#pragma once
class cBullet abstract
{
protected:
	texture* m_image;
	D3DXVECTOR2 m_pos;

	double m_size;
public:
	cBullet(const D3DXVECTOR2& pos, double size);
	virtual ~cBullet();

	virtual void Update() PURE;
	void Render();

	bool IsOutMap();
};