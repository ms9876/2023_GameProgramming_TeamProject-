#include "pch.h"
#include "MainMap_W.h"
#include "ResMgr.h"
#include "Texture.h"

MainMap_W::MainMap_W()
	: m_pTex(nullptr)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"Miro_W", L"Texture\\Miro1_White_Button.bmp");
}

MainMap_W::~MainMap_W()
{
}

void MainMap_W::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();
	BitBlt(_dc
		, (int)(vPos.x - vScale.x / 2)
		, (int)(vPos.y - vScale.y / 2)
		, Width, Height, m_pTex->GetDC()
		, 0, 0, SRCCOPY);
}
