#pragma once
#include "cBullet.h"

class cPlayerBullet : public cBullet
{
private:

public:
	cPlayerBullet(const D3DXVECTOR2& pos);
	~cPlayerBullet();

	virtual void Update() override;
};

