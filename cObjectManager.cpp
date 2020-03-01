#include "DXUT.h"
#include "cObjectManager.h"
#include "cObject.h"

cObject* cObjectManager::AddObject(cObject* _newObj)
{
    if (_newObj)
        m_objList.push_back(_newObj);
    else
    {
        DEBUG_LOG("빈 obj를 할당하려 했습니다");
    }

    return _newObj;
}

void cObjectManager::Update()
{
    for (auto iter = m_objList.begin(); iter != m_objList.end(); )
    {
        if (!(*iter)->IsValid())
        {
            delete (*iter);
            iter = m_objList.erase(iter);
        }
        else
            ++iter;
    }

    for (auto iter : m_objList)
        iter->Update();
}

void cObjectManager::Render()
{
    for (auto iter : m_objList)
        iter->Render();
}
