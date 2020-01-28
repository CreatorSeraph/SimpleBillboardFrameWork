#pragma once

class cBullet;
class cPlayer
{
private:
	texture* m_playerImage;

	D3DXVECTOR2 m_pos;

	vector<cBullet*>& m_fireBullet;
public:
	cPlayer(vector<cBullet*>& playerBullet);
	~cPlayer();

	void Update();
	void Render();

	D3DXVECTOR2 GetPos() { return m_pos; }
};

