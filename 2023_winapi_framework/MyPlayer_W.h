#pragma once
#include "Object.h"
class Texture;
class MyPlayer_W :
    public Object
{
public:
    MyPlayer_W();
    ~MyPlayer_W();

public:
    void Update() override;
    void Render(HDC _dc) override;

private:
    Texture* m_pTex;
};

