#include "pch.h"
#include "EndScene.h"
#include "ReStartButton.h"
#include "OutButton.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "Core.h"

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
}

void EndScene::Update()
{
	Scene::Update();
}

void EndScene::Render(HDC _dc)
{	
	TextOut(_dc, Core::GetInst()->GetResolution().x / 2 - 65, Core::GetInst()->GetResolution().y / 2 - 160, L"CLEAR THE MAZE!!", 16);
	Scene::Render(_dc);
}

void EndScene::Release()
{
}
