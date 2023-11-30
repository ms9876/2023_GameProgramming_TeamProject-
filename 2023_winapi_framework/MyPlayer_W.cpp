#include "pch.h"
#include "MyPlayer_W.h"
#include "ResMgr.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Texture.h"
#include "Core.h"
#include "SceneMgr.h"
#include "PosManager.h"

MyPlayer_W::MyPlayer_W()
	: m_pTex(nullptr)
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
	, currentTime(0)
	, waitTime(1.5f)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"MyPlayer_W", L"Texture\\Player_W.bmp");
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

	currentTime += fDT;

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

		if (currentTime >= waitTime)
		{
			if (colorLeft1 == RGB(35, 156, 83) || colorLeft2 == RGB(35, 156, 83) || colorLeft3 == RGB(35, 156, 83))
			{
				// 진한 초록
				PosManager::GetInst()->SetPos_B(Vec2({ Core::GetInst()->GetResolution().x / 2 - 20, Core::GetInst()->GetResolution().y / 2 - 120 }));
				currentTime = 0;
				SceneMgr::GetInst()->LoadScene(L"MainScene_W");
			}
			if (colorLeft1 == RGB(0, 0, 201) || colorLeft2 == RGB(0, 0, 201) || colorLeft3 == RGB(0, 0, 201))
			{
				// 진한 파랑색
				PosManager::GetInst()->SetPos_B(Vec2({ Core::GetInst()->GetResolution().x / 2 + 200, Core::GetInst()->GetResolution().y / 2 + 200 }));
				currentTime = 0;
				SceneMgr::GetInst()->LoadScene(L"MainScene_W");
			}
		}
		
	}
	if (KEY_PRESS(KEY_TYPE::D))
	{
		if (colorRight1 != RGB(255, 255, 255) && colorRight2 != RGB(255, 255, 255) && colorRight3 != RGB(255, 255, 255))
			vPos.x += 70.f * fDT;

		if (currentTime >= waitTime)
		{
			if (colorRight1 == RGB(239, 243, 0) || colorRight2 == RGB(239, 243, 0) || colorRight3 == RGB(239, 243, 0))
			{
				// 노랑색
				PosManager::GetInst()->SetPos_B(Vec2({ Core::GetInst()->GetResolution().x / 2 - 70, Core::GetInst()->GetResolution().y / 2 - 197 }));
				currentTime = 0;
				SceneMgr::GetInst()->LoadScene(L"MainScene_W");
			}
			if (colorRight1 == RGB(0, 239, 95) || colorRight2 == RGB(0, 239, 95) || colorRight3 == RGB(0, 239, 95))
			{
				// 연두색
				PosManager::GetInst()->SetPos_B(Vec2({ Core::GetInst()->GetResolution().x / 2 + 27, Core::GetInst()->GetResolution().y / 2 + 20 }));
				currentTime = 0;
				SceneMgr::GetInst()->LoadScene(L"MainScene_W");
			}
			if (colorRight1 == RGB(254, 214, 203) || colorRight2 == RGB(254, 214, 203) || colorRight3 == RGB(254, 214, 203))
			{
				// 연분홍색
				PosManager::GetInst()->SetPos_B(Vec2({ Core::GetInst()->GetResolution().x / 2 - 197, Core::GetInst()->GetResolution().y / 2 - 65 }));
				currentTime = 0;
				SceneMgr::GetInst()->LoadScene(L"MainScene_W");
			}
			if (colorRight1 == RGB(237, 243, 186) || colorRight2 == RGB(237, 243, 186) || colorRight3 == RGB(237, 243, 186))
			{
				// 연노랑색
				PosManager::GetInst()->SetPos_B(Vec2({ Core::GetInst()->GetResolution().x / 2 + 150, Core::GetInst()->GetResolution().y / 2 - 197 }));
				currentTime = 0;
				SceneMgr::GetInst()->LoadScene(L"MainScene_W");
			}
		}
		
	}
	if (KEY_PRESS(KEY_TYPE::W))
	{
		if (colorTop1 != RGB(255, 255, 255) && colorTop2 != RGB(255, 255, 255) && colorTop3 != RGB(255, 255, 255))
			vPos.y -= 70.f * fDT;

		if (currentTime >= waitTime)
		{
			if (colorTop1 == RGB(154, 154, 154) || colorTop2 == RGB(154, 154, 154) || colorTop3 == RGB(154, 154, 154))
			{
				// 회색
				PosManager::GetInst()->SetPos_B(Vec2({ Core::GetInst()->GetResolution().x / 2 + 200, Core::GetInst()->GetResolution().y / 2 - 190 }));
				currentTime = 0;
				SceneMgr::GetInst()->LoadScene(L"MainScene_W");
			}
		}
	}
	if (KEY_PRESS(KEY_TYPE::S))
	{
		if (colorBottom1 != RGB(255, 255, 255) && colorBottom2 != RGB(255, 255, 255) && colorBottom3 != RGB(255, 255, 255))
			vPos.y += 70.f * fDT;

		if (currentTime >= waitTime)
		{
			if (colorBottom1 == RGB(160, 123, 113) || colorBottom2 == RGB(160, 123, 113) || colorBottom3 == RGB(160, 123, 113))
			{
				// 연갈색
				PosManager::GetInst()->SetPos_B(Vec2({ Core::GetInst()->GetResolution().x / 2 - 110, Core::GetInst()->GetResolution().y / 2 + 160 }));
				currentTime = 0;
				SceneMgr::GetInst()->LoadScene(L"MainScene_W");
			}
			if (colorBottom1 == RGB(165, 0, 0) || colorBottom2 == RGB(165, 0, 0) || colorBottom3 == RGB(165, 0, 0))
			{
				// 빨강색
				PosManager::GetInst()->SetPos_B(Vec2({ Core::GetInst()->GetResolution().x / 2 - 197, Core::GetInst()->GetResolution().y / 2 + 100 }));
				currentTime = 0;
				SceneMgr::GetInst()->LoadScene(L"MainScene_W");
			}
			if (colorBottom1 == RGB(112, 181, 254) || colorBottom2 == RGB(112, 181, 254) || colorBottom3 == RGB(112, 181, 254))
			{
				// 하늘색
				PosManager::GetInst()->SetPos_B(Vec2({ Core::GetInst()->GetResolution().x / 2 - 65, Core::GetInst()->GetResolution().y / 2 + 200 }));
				currentTime = 0;
				SceneMgr::GetInst()->LoadScene(L"MainScene_W");
			}
			if (colorBottom1 == RGB(165, 102, 255) || colorBottom2 == RGB(165, 102, 255) || colorBottom3 == RGB(165, 102, 255))
			{
				// 보라색
				PosManager::GetInst()->SetPos_B(Vec2({ Core::GetInst()->GetResolution().x / 2 - 100, Core::GetInst()->GetResolution().y / 2 - 110 }));
				currentTime = 0;
				SceneMgr::GetInst()->LoadScene(L"MainScene_W");
			}
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
