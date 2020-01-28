#pragma once

class cBullet;
class cBulletAdmin
{
private:
	vector<cBullet*> m_playerBullet;

private:
	void CheckCollision();
	
public:
	cBulletAdmin();
	~cBulletAdmin();

	void Reset();

	void Update();
	void Render();

	vector<cBullet*>& GetPlayerBullet() { return m_playerBullet; }
};

