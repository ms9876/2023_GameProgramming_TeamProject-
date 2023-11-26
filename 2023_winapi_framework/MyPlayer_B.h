#pragma once
#include "Object.h"
class Texture;
class MyPlayer_B :
    public Object
{
public:
    MyPlayer_B();
    ~MyPlayer_B();

public:
    void Update() override;
    void Render(HDC _dc) override;

private:
    Texture* m_pTex;
};

