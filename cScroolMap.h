#pragma once
class cScroolMap
{
private:
	float m_scrool;
	cTexture* m_backGround;
public:
	cScroolMap();
	~cScroolMap();

	void Update(float speed);
	void Render();

	float GetScrool() { return m_scrool; }
};

