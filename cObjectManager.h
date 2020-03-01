#pragma once
#include "singleton.h"
#include <list>

class cObject;
class cObjectManager : public singleton<cObjectManager>
{
private:
    std::list<cObject*> m_objList;
public:
    cObject* AddObject(cObject* _newObj);

    void Update();
    void Render();
};

#define OBJMANAGER cObjectManager::GetInstance()