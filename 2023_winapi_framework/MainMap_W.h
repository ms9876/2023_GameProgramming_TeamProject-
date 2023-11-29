#pragma once
#include "Object.h"
class Texture;
class MainMap_W :
    public Object
{
public:
    MainMap_W();
    ~MainMap_W();

public:
    virtual void Render(HDC _dc) override;

private:
    Texture* m_pTex;
};

