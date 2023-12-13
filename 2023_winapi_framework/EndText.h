#pragma once
#include "Object.h"
class Texture;
class EndText : 
	public Object
{
public:
	EndText();
	~EndText();

public:
	void Render(HDC _dc) override;

private:
	Texture* m_pTex;
};

