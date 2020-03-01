#pragma once
#include "cObject.h"

class cScroolMap : public cObject
{
private:
	float m_scrool;
	float m_scroolSpeed;
	cTexture* m_backGround;
public:
	cScroolMap();
	~cScroolMap();

	virtual void Update() override;
	virtual void Render() override;

	float GetScrool() { return m_scrool; }
	float GetScroolSpeed() { return m_scroolSpeed; }
};

