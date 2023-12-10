#pragma once
#include "Object.h"
class SubTwoMap :
    public Object
{
public:
	SubTwoMap();
	~SubTwoMap();

public:
	void Update() override;
	void Render(HDC _dc) override;

private:
    float currentTime;
    float checkTime;
    float cantpressTime;
    float changeTime;

    int currentColor;
    int pressCount;
    int winCount;

    RECT rect;
    HBRUSH brush;

};

