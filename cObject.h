#pragma once
#include <string>

class cObject abstract
{
private:
    std::string m_objName;
    bool m_willDelete;
public:
    cObject(const std::string& _name = "unnamedObj");
    virtual ~cObject() = default;

    virtual void Init();
    virtual void Release();
    virtual void Update();
    virtual void Render();
public:
    void DestroyObj() { m_willDelete = true; }
    bool IsValid() { return m_willDelete; }
};

