#include "pch.h"
#include "StartScene.h"
#include "StartButton.h"
#include "OutButton.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "Core.h"

void StartScene::Init()
{
	Object* pStartButton = new StartButton;
	pStartButton->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2 - 25, Core::GetInst()->GetResolution().y / 2 })));
	pStartButton->SetScale(Vec2(100.f, 100.f));
	AddObject(pStartButton, OBJECT_GROUP::PRESSBUTTON);

	Object* pOutButton = new OutButton;
	pOutButton->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2 - 25, Core::GetInst()->GetResolution().y / 2 + 100 })));
	pOutButton->SetScale(Vec2(100.f, 100.f));
	AddObject(pOutButton, OBJECT_GROUP::PRESSBUTTON);
}

void StartScene::Update()
{
	Scene::Update();
}

void StartScene::Render(HDC _dc)
{
	TextOut(_dc, Core::GetInst()->GetResolution().x / 2 - 52, Core::GetInst()->GetResolution().y / 2 - 200, L"컬러 미로 게임", 8);
	Scene::Render(_dc);
}

void StartScene::Release()
{
}
