#include "pch.h"
#include "MyPlayer_B.h"
#include "ResMgr.h"
#include "Core.h"
#include "SceneMgr.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Texture.h"
#include "MyPlayer_W.h"
#include "PosManager.h"

// ����� �÷��̾�
MyPlayer_B::MyPlayer_B()
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
	m_pTex = ResMgr::GetInst()->TexLoad(L"MyPlayer_B", L"Texture\\Player_B.bmp");
}

MyPlayer_B::~MyPlayer_B()
{
}

void MyPlayer_B::Update()
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
		if (colorLeft1 != RGB(0, 0, 0) && colorLeft2 != RGB(0, 0, 0) && colorLeft3 != RGB(0, 0, 0))
			vPos.x -= 70.f * fDT;
		if (currentTime >= waitTime)
		{
			if (colorLeft1 == RGB(165, 102, 255) || colorLeft2 == RGB(165, 102, 255) || colorLeft3 == RGB(165, 102, 255))
			{
				// �����
				PosManager::GetInst()->SetPos_W(Vec2({ Core::GetInst()->GetResolution().x / 2 - 3, Core::GetInst()->GetResolution().y / 2 + 80 }));
				currentTime = 0;
				SceneMgr::GetInst()->LoadScene(L"MainScene_B");
			}
		}
	}
	if (KEY_PRESS(KEY_TYPE::D))
	{
		if (colorRight1 != RGB(0, 0, 0) && colorRight2 != RGB(0, 0, 0) && colorRight3 != RGB(0, 0, 0))
			vPos.x += 70.f * fDT;

		if (currentTime >= waitTime)
		{
			if (colorRight1 == RGB(239, 243, 0) || colorRight2 == RGB(239, 243, 0) || colorRight3 == RGB(239, 243, 0))
			{
				// �����
				PosManager::GetInst()->SetPos_W(Vec2({ Core::GetInst()->GetResolution().x / 2 + 45, Core::GetInst()->GetResolution().y / 2 - 203 }));
				currentTime = 0;
				SceneMgr::GetInst()->LoadScene(L"MainScene_B");
			}
			if (colorRight1 == RGB(237, 243, 186) || colorRight2 == RGB(237, 243, 186) || colorRight3 == RGB(237, 243, 186))
			{
				// �������
				PosManager::GetInst()->SetPos_W(Vec2({ Core::GetInst()->GetResolution().x / 2 + 200, Core::GetInst()->GetResolution().y / 2 - 43 }));
				currentTime = 0;
				SceneMgr::GetInst()->LoadScene(L"MainScene_B");
			}
			if (colorRight1 == RGB(254, 214, 203) || colorRight2 == RGB(254, 214, 203) || colorRight3 == RGB(254, 214, 203))
			{
				// ����ȫ��
				PosManager::GetInst()->SetPos_W(Vec2({ Core::GetInst()->GetResolution().x / 2 - 170, Core::GetInst()->GetResolution().y / 2 - 82 }));
				currentTime = 0;
				SceneMgr::GetInst()->LoadScene(L"MainScene_B");
			}
		}
	}
	if (KEY_PRESS(KEY_TYPE::W))
	{
		if (colorTop1 != RGB(0, 0, 0) && colorTop2 != RGB(0, 0, 0) && colorTop3 != RGB(0, 0, 0))
			vPos.y -= 70.f * fDT;

		if (currentTime >= waitTime)
		{
			if (colorTop1 == RGB(154, 154, 154) || colorTop2 == RGB(154, 154, 154) || colorTop3 == RGB(154, 154, 154))
			{
				// ȸ��
				PosManager::GetInst()->SetPos_W(Vec2({ Core::GetInst()->GetResolution().x / 2 - 203, Core::GetInst()->GetResolution().y / 2 + 150 }));
				currentTime = 0;
				SceneMgr::GetInst()->LoadScene(L"MainScene_B");
			}
			if (colorTop1 == RGB(160, 123, 113) || colorTop2 == RGB(160, 123, 113) || colorTop3 == RGB(160, 123, 113))
			{
				// ������
				PosManager::GetInst()->SetPos_W(Vec2({ Core::GetInst()->GetResolution().x / 2 - 163, Core::GetInst()->GetResolution().y / 2 }));
				currentTime = 0;
				SceneMgr::GetInst()->LoadScene(L"MainScene_B");
			}
		}
	}
	if (KEY_PRESS(KEY_TYPE::S))
	{
		if (colorBottom1 != RGB(0, 0, 0) && colorBottom2 != RGB(0, 0, 0) && colorBottom3 != RGB(0, 0, 0))
			vPos.y += 70.f * fDT;

		if (currentTime >= waitTime)
		{
			if (colorBottom1 == RGB(35, 156, 83) || colorBottom2 == RGB(35, 156, 83) || colorBottom3 == RGB(35, 156, 83))
			{
				// ���� �ʷϻ�
				PosManager::GetInst()->SetPos_W(Vec2({ Core::GetInst()->GetResolution().x / 2 - 150, Core::GetInst()->GetResolution().y / 2 - 123 }));
				currentTime = 0;
				SceneMgr::GetInst()->LoadScene(L"MainScene_B");
			}
			if (colorBottom1 == RGB(165, 0, 0) || colorBottom2 == RGB(165, 0, 0) || colorBottom3 == RGB(165, 0, 0))
			{
				// ������
				PosManager::GetInst()->SetPos_W(Vec2({ Core::GetInst()->GetResolution().x / 2 - 203, Core::GetInst()->GetResolution().y / 2 + 85 }));
				currentTime = 0;
				SceneMgr::GetInst()->LoadScene(L"MainScene_B");
			}
			if (colorBottom1 == RGB(112, 181, 254) || colorBottom2 == RGB(112, 181, 254) || colorBottom3 == RGB(112, 181, 254))
			{
				// �ϴû�
				PosManager::GetInst()->SetPos_W(Vec2({ Core::GetInst()->GetResolution().x / 2 + 205, Core::GetInst()->GetResolution().y / 2 - 90 }));
				currentTime = 0;
				SceneMgr::GetInst()->LoadScene(L"MainScene_B");
			}
			if (colorBottom1 == RGB(0, 239, 95) || colorBottom2 == RGB(0, 239, 95) || colorBottom3 == RGB(0, 239, 95))
			{
				// ���λ�
				PosManager::GetInst()->SetPos_W(Vec2({ Core::GetInst()->GetResolution().x / 2 + 5, Core::GetInst()->GetResolution().y / 2 - 123 }));
				currentTime = 0;
				SceneMgr::GetInst()->LoadScene(L"MainScene_B");
			}
			if (colorBottom1 == RGB(0, 0, 201) || colorBottom2 == RGB(0, 0, 201) || colorBottom3 == RGB(0, 0, 201))
			{
				// ���� �Ķ���
				PosManager::GetInst()->SetPos_W(Vec2({ Core::GetInst()->GetResolution().x / 2 + 50, Core::GetInst()->GetResolution().y / 2 + 166 }));
				currentTime = 0;
				SceneMgr::GetInst()->LoadScene(L"MainScene_B");
			}
		}
		
	}
	SetPos(vPos);
}

void MyPlayer_B::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();

	StretchBlt(_dc
		, (int)(vPos.x - vScale.x / 2)
		, (int)(vPos.y - vScale.y / 2)
		, vScale.x, vScale.y, m_pTex->GetDC()
		, 0, 0, Width, Height, SRCCOPY);
}
