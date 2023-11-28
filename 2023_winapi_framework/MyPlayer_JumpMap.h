#pragma once
#include "Object.h"
class Texture;	
class MyPlayer_JumpMap : public Object
{
public :
	MyPlayer_JumpMap();
	~MyPlayer_JumpMap();

public:
	void Update() override;
	void Render(HDC _dc) override;
	void Jump(Vec2 vPos);
	void Gravity(Vec2 vPos);

private:
	Texture* m_pTex;
	bool m_bIsJumping;   
	float m_fJumpVelocity;
};

