#include "pch.h"
#include "EndText.h"
#include "ResMgr.h"
#include "Texture.h"

EndText::EndText() : 
	m_pTex(nullptr)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"ClearText", L"Texture\\clear.bmp");
}

EndText::~EndText()
{
}

void EndText::Render(HDC _dc)
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
