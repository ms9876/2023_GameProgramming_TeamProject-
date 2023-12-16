#include "pch.h"
#include "JumpMap_B.h"
#include "CollisionMgr.h"
#include "ResMgr.h"
#include "Texture.h"

JumpMap_B::JumpMap_B() : m_pTex(nullptr)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"JumpMap_1", L"Texture\\JumpMap_1.bmp");
}

JumpMap_B::~JumpMap_B()
{

}

void JumpMap_B::Render(HDC _dc)
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
