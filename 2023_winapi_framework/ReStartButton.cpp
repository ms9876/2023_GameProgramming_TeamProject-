#include "pch.h"
#include "ReStartButton.h"
#include "ResMgr.h"
#include "KeyMgr.h"
#include "Texture.h"
#include "SceneMgr.h"
#include "PosManager.h"
#include "PlayTimeMgr.h"

ReStartButton::ReStartButton()
	: m_pTex(nullptr)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"ReStartButton", L"Texture\\ReStartButton.bmp");
}

ReStartButton::~ReStartButton()
{
}

void ReStartButton::Update()
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	if ((vPos.x - vScale.x / 2) < KeyMgr::GetInst()->GetMousePos().x && (vPos.x + vScale.x) > KeyMgr::GetInst()->GetMousePos().x
		&& (vPos.y - vScale.y / 2) < KeyMgr::GetInst()->GetMousePos().y && (vPos.y + vScale.y / 1000) > KeyMgr::GetInst()->GetMousePos().y)
	{
		if (KEY_PRESS(KEY_TYPE::LBUTTON))
		{
			ResMgr::GetInst()->Play(L"Click");
			PosManager::GetInst()->Init();
			PlayTimeMgr::GetInst()->Init();
			SceneMgr::GetInst()->LoadScene(L"StartScene");
		}
	}
}

void ReStartButton::Render(HDC _dc)
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
