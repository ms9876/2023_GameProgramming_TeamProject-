#include "pch.h"
#include "MyPlayer_JumpMap.h"
#include "ResMgr.h"
#include "KeyMgr.h"
#include "Texture.h"
#include "TimeMgr.h"
#include "Collider.h"

MyPlayer_JumpMap::MyPlayer_JumpMap() : m_pTex(nullptr), m_bIsJumping(false), m_fJumpVelocity(0.0f)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"MyPlayer_W", L"Texture\\Player_W.bmp");

	CreateCollider();
	GetCollider()->SetScale(Vec2(50.f, 50.f));
}

MyPlayer_JumpMap::~MyPlayer_JumpMap()
{
}

void MyPlayer_JumpMap::Update()
{
	Vec2 vPos = GetPos();

	if (KEY_PRESS(KEY_TYPE::LEFT))
	{
		vPos.x -= 50.f * fDT;
	}
	if (KEY_PRESS(KEY_TYPE::RIGHT))
	{
		vPos.x += 50.f * fDT;
	}
	if (KEY_PRESS(KEY_TYPE::UP))
	{
		vPos.y -= 50.f * fDT;
	}
	if (KEY_PRESS(KEY_TYPE::DOWN))
	{
		vPos.y += 50.f * fDT;
	}

	SetPos(vPos);

	if (KEY_PRESS(KEY_TYPE::SPACE)) {
		if (!m_bIsJumping) {
			Jump(vPos);
		}
	}

	vPos = GetPos();

	if (m_bIsJumping) {
		Gravity(vPos);
		
	}
}

void MyPlayer_JumpMap::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();
	StretchBlt(_dc
		, (int)(vPos.x - vScale.x / 2)
		, (int)(vPos.y - vScale.y / 2)
		, Width / 8, Height / 8, m_pTex->GetDC()
		, 0, 0, Width, Height, SRCCOPY);
}

void MyPlayer_JumpMap::Jump(Vec2 vPos)
{
	m_fJumpVelocity = 20.0f;
	m_bIsJumping = true;

	vPos.y -= 50.f;

	SetPos(vPos);

}

void MyPlayer_JumpMap::Gravity(Vec2 vPos)
{
	vPos.y += m_fJumpVelocity * fDT;
		
	m_fJumpVelocity -= 10.0f * fDT;

	if (m_fJumpVelocity <= 0.0f) {  // 이거 콜라이더 부분으로 나중에 바꿔주기
		vPos.y = 0.0f;
		m_bIsJumping = false;
		m_fJumpVelocity = 0.0f;
	}

	SetPos(vPos);
}
