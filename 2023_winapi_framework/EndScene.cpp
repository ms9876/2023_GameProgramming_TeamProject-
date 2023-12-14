#include "pch.h"
#include "EndScene.h"
#include "ReStartButton.h"
#include "OutButton.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "Core.h"
#include "PlayTimeMgr.h"
#include "ResMgr.h"

void EndScene::Init()
{
	Object* pReStartButton = new ReStartButton;
	pReStartButton->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2 - 25, Core::GetInst()->GetResolution().y / 2 })));
	pReStartButton->SetScale(Vec2(100.f, 100.f));
	AddObject(pReStartButton, OBJECT_GROUP::PRESSBUTTON);

	Object* pOutButton = new OutButton;
	pOutButton->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2 - 25, Core::GetInst()->GetResolution().y / 2 + 100 })));
	pOutButton->SetScale(Vec2(100.f, 100.f));
	AddObject(pOutButton, OBJECT_GROUP::PRESSBUTTON);

	ResMgr::GetInst()->LoadSound(L"Click", L"Sound\\Coin-1.wav", false);

	time = PlayTimeMgr::GetInst()->GetPlayTime();
}

void EndScene::Update()
{
	Scene::Update();
}

void EndScene::Render(HDC _dc)
{	
	wstring s = std::to_wstring(time);
	TextOut(_dc, Core::GetInst()->GetResolution().x / 2 - 65, Core::GetInst()->GetResolution().y / 2 - 160, L"CLEAR THE MAZE!!", 16);
	TextOut(_dc, Core::GetInst()->GetResolution().x / 2 - 35, Core::GetInst()->GetResolution().y / 2 - 180, s.c_str(), s.length());
	Scene::Render(_dc);
}

void EndScene::Release()
{
}
