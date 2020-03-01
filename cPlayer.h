#pragma once
#include "cObject.h"

class cBullet;
class cPlayer : public cObject
{
private:
	cTexture* m_playerImage;

	D3DXVECTOR2 m_pos;

	//vector<cBullet*>& m_fireBullet;
public:
	cPlayer();
	~cPlayer();

	virtual void Update() override;
	virtual void Render() override;

	D3DXVECTOR2 GetPos() { return m_pos; }
};

