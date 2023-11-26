#include "pch.h"
#include "MyPlayer_W.h"
#include "ResMgr.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Texture.h"
#include "Collider.h"

MyPlayer_W::MyPlayer_W()
	: m_pTex(nullptr)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"MyPlayer_W", L"Texture\\Player_W.bmp");
	CreateCollider();
	GetCollider()->SetScale(Vec2(50.f, 50.f));
}

MyPlayer_W::~MyPlayer_W()
{
}

void MyPlayer_W::Update()
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
}

void MyPlayer_W::Render(HDC _dc)
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
