#pragma once
#include "Object.h"
class Texture;
class JumpMap_B : public Object
{
public :
	JumpMap_B();
	~JumpMap_B();

public:
	void Render(HDC _dc) override;

private:
	Texture* m_pTex;	
};

