#include "pch.h"
#include "MainMap_B.h"
#include "ResMgr.h"
#include "Texture.h"

MainMap_B::MainMap_B()
	: m_pTex(nullptr)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"Miro_B", L"Texture\\Miro1_Black_Button.bmp");
}

MainMap_B::~MainMap_B()
{
}

void MainMap_B::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();
	BitBlt(_dc
		,(int)(vPos.x - vScale.x /2)
		,(int)(vPos.y - vScale.y /2)
		, Width,Height, m_pTex->GetDC()
		,0,0,SRCCOPY);
}
