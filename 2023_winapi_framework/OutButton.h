#pragma once
#include "Object.h"
class Texture;
class OutButton :
    public Object
{
public:
    OutButton();
    ~OutButton();

public:
    void Update() override;
    void Render(HDC _dc) override;

private:
    Texture* m_pTex;
};

