#include "pch.h"
#include "OutButton.h"
#include "ResMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "Texture.h"

OutButton::OutButton()
	: m_pTex(nullptr)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"OutButton", L"Texture\\OutButton.bmp");
}

OutButton::~OutButton()
{
}

void OutButton::Update()
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	if ((vPos.x - vScale.x / 2) < KeyMgr::GetInst()->GetMousePos().x && (vPos.x + vScale.x / 2) > KeyMgr::GetInst()->GetMousePos().x
		&& (vPos.y - vScale.y / 2) < KeyMgr::GetInst()->GetMousePos().y && (vPos.y + vScale.y / 2) > KeyMgr::GetInst()->GetMousePos().y)
	{
		if (KEY_PRESS(KEY_TYPE::LBUTTON))
			PostQuitMessage(0);
	}
}

void OutButton::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();
	StretchBlt(_dc
		, (int)(vPos.x - vScale.x / 2)
		, (int)(vPos.y - vScale.y / 2)
		, Width * 5, Height * 5, m_pTex->GetDC()
		, 0, 0, Width, Height, SRCCOPY);
}
