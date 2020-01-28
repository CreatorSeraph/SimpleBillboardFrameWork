#pragma once
#include "cScene.h"

class cScroolMap;
class cPlayer;
class cBulletAdmin;
class cIngameScene : public cScene
{
private:
	cScroolMap* m_map;
	cPlayer* m_player;
	cBulletAdmin* m_bullet;
public:
	cIngameScene();
	~cIngameScene();

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;
};

