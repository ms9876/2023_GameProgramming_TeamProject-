#pragma once
#include"Object.h"
class Texture;
class ReStartButton :
	public Object
{
public :
	ReStartButton();
	~ReStartButton();

public:
	void Update() override;
	void Render(HDC _dc) override;

private:
	Texture* m_pTex;
};

