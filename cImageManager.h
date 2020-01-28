#pragma once
#include "singleton.h"

class cTexture;
class cImageManager : public singleton<cImageManager>
{
private:
	map<string, cTexture*> m_images;
public:
	cImageManager();
	~cImageManager();

	cTexture* AddImage(const string& key, const string& path);
	cTexture* FindImage(const string& key);
};

#define IMAGEMANAGER cImageManager::GetInstance()