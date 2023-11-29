#include "pch.h"
#include "MyPlayer_W.h"
#include "ResMgr.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Texture.h"
#include "Core.h"
#include "SceneMgr.h"

MyPlayer_W::MyPlayer_W()
	: m_pTex(nullptr)
	, m_pMapTex(nullptr)
	, colorLeft1(RGB(0, 0, 0))
	, colorLeft2(RGB(0, 0, 0))
	, colorLeft3(RGB(0, 0, 0))
	, colorRight1(RGB(0, 0, 0))
	, colorRight2(RGB(0, 0, 0))
	, colorRight3(RGB(0, 0, 0))
	, colorTop1(RGB(0, 0, 0))
	, colorTop2(RGB(0, 0, 0))
	, colorTop3(RGB(0, 0, 0))
	, colorBottom1(RGB(0, 0, 0))
	, colorBottom2(RGB(0, 0, 0))
	, colorBottom3(RGB(0, 0, 0))
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"MyPlayer_W", L"Texture\\Player_W.bmp");
	m_pMapTex = ResMgr::GetInst()->TexLoad(L"Miro_B", L"Texture\\Miro1_Black_Button.bmp");
}

MyPlayer_W::~MyPlayer_W()
{
}

void MyPlayer_W::Update()
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = vScale.x;
	int Height = vScale.y;
	colorLeft1 = GetPixel(Core::GetInst()->GetBackDC(), (vPos.x - Width / 2) - 2, vPos.y);
	colorLeft2 = GetPixel(Core::GetInst()->GetBackDC(), (vPos.x - Width / 2) - 2, (vPos.y - Height / 2));
	colorLeft3 = GetPixel(Core::GetInst()->GetBackDC(), (vPos.x - Width / 2) - 2, (vPos.y + Height / 2));

	colorRight1 = GetPixel(Core::GetInst()->GetBackDC(), (vPos.x + Width / 2) + 1, vPos.y);
	colorRight2 = GetPixel(Core::GetInst()->GetBackDC(), (vPos.x + Width / 2) + 1, (vPos.y - Height / 2));
	colorRight3 = GetPixel(Core::GetInst()->GetBackDC(), (vPos.x + Width / 2) + 1, (vPos.y + Height / 2));

	colorTop1 = GetPixel(Core::GetInst()->GetBackDC(), vPos.x, (vPos.y - Height / 2) - 2);
	colorTop2 = GetPixel(Core::GetInst()->GetBackDC(), (vPos.x - Width / 2) - 2, (vPos.y - Height / 2) - 2);
	colorTop3 = GetPixel(Core::GetInst()->GetBackDC(), (vPos.x + Width / 2) + 1, (vPos.y - Height / 2) - 2);

	colorBottom1 = GetPixel(Core::GetInst()->GetBackDC(), vPos.x, (vPos.y + Height / 2) + 1);
	colorBottom2 = GetPixel(Core::GetInst()->GetBackDC(), (vPos.x - Width / 2) - 2, (vPos.y + Height / 2) + 1);
	colorBottom3 = GetPixel(Core::GetInst()->GetBackDC(), (vPos.x + Width / 2) + 1, (vPos.y + Height / 2) + 1);

	if (KEY_PRESS(KEY_TYPE::A))
	{
		if(colorLeft1 != RGB(255, 255, 255) && colorLeft2 != RGB(255, 255, 255) && colorLeft3 != RGB(255, 255, 255))
			vPos.x -= 70.f * fDT;
		if (colorRight1 == RGB(35, 156, 83) || colorRight2 == RGB(35, 156, 83) || colorRight3 == RGB(35, 156, 83))
		{
			SceneMgr::GetInst()->LoadScene(L"MainScene_W");
		}
		if (colorRight1 == RGB(0, 0, 201) || colorRight2 == RGB(0, 0, 201) || colorRight3 == RGB(0, 0, 201))
		{
			SceneMgr::GetInst()->LoadScene(L"MainScene_W");
		}
	}
	if (KEY_PRESS(KEY_TYPE::D))
	{
		if (colorRight1 != RGB(255, 255, 255) && colorRight2 != RGB(255, 255, 255) && colorRight3 != RGB(255, 255, 255))
			vPos.x += 70.f * fDT;
		if (colorRight1 == RGB(239, 243, 0) || colorRight2 == RGB(239, 243, 0) || colorRight3 == RGB(239, 243, 0))
		{
			SceneMgr::GetInst()->LoadScene(L"MainScene_W");
		}
		if (colorRight1 == RGB(0, 239, 95) || colorRight2 == RGB(0, 239, 95) || colorRight3 == RGB(0, 239, 95))
		{
			SceneMgr::GetInst()->LoadScene(L"MainScene_W");
		}
		if (colorRight1 == RGB(254, 214, 203) || colorRight2 == RGB(254, 214, 203) || colorRight3 == RGB(254, 214, 203))
		{
			SceneMgr::GetInst()->LoadScene(L"MainScene_W");
		}
		if (colorRight1 == RGB(237, 243, 186) || colorRight2 == RGB(237, 243, 186) || colorRight3 == RGB(237, 243, 186))
		{
			SceneMgr::GetInst()->LoadScene(L"MainScene_W");
		}
	}
	if (KEY_PRESS(KEY_TYPE::W))
	{
		if (colorTop1 != RGB(255, 255, 255) && colorTop2 != RGB(255, 255, 255) && colorTop3 != RGB(255, 255, 255))
			vPos.y -= 70.f * fDT;
	}
	if (KEY_PRESS(KEY_TYPE::S))
	{
		if (colorBottom1 != RGB(255, 255, 255) && colorBottom2 != RGB(255, 255, 255) && colorBottom3 != RGB(255, 255, 255))
			vPos.y += 70.f * fDT;
		if (colorRight1 == RGB(160, 123, 113) || colorRight2 == RGB(160, 123, 113) || colorRight3 == RGB(160, 123, 113))
		{
			SceneMgr::GetInst()->LoadScene(L"MainScene_W");
		}
		if (colorRight1 == RGB(165, 0, 0) || colorRight2 == RGB(165, 0, 0) || colorRight3 == RGB(165, 0, 0))
		{
			SceneMgr::GetInst()->LoadScene(L"MainScene_W");
		}
		if (colorRight1 == RGB(112, 181, 254) || colorRight2 == RGB(112, 181, 254) || colorRight3 == RGB(112, 181, 254))
		{
			SceneMgr::GetInst()->LoadScene(L"MainScene_W");
		}
		if (colorRight1 == RGB(165, 102, 255) || colorRight2 == RGB(165, 102, 255) || colorRight3 == RGB(165, 102, 255))
		{
			SceneMgr::GetInst()->LoadScene(L"MainScene_W");
		}
	}
	SetPos(vPos);
}

void MyPlayer_W::Render(HDC _dc)
{
	wstring str;
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();

	StretchBlt(_dc
		, (int)(vPos.x - vScale.x/2)
		, (int)(vPos.y - vScale.y/2)
		,  vScale.x, vScale.y, m_pTex->GetDC()
		, 0, 0, Width, Height, SRCCOPY);
}
