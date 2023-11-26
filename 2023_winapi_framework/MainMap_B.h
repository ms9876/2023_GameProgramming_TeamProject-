#pragma once
#include "Object.h"
class Texture;
class MainMap_B :
    public Object
{
public:
    MainMap_B();
    ~MainMap_B();

public:
    void Render(HDC _dc) override;

private:
    Texture* m_pTex;
};

