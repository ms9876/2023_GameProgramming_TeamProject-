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

    COLORREF colorLeft1;
    COLORREF colorLeft2;
    COLORREF colorLeft3;

    COLORREF colorRight1;
    COLORREF colorRight2;
    COLORREF colorRight3;

    COLORREF colorTop1;
    COLORREF colorTop2;
    COLORREF colorTop3;

    COLORREF colorBottom1;
    COLORREF colorBottom2;
    COLORREF colorBottom3;

    float currentTime;
    float waitTime;
};

