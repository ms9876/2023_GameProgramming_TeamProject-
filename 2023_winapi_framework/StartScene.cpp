#include "pch.h"
#include "StartScene.h"
#include "StartButton.h"
#include "Core.h"

void StartScene::Init()
{
	Object* pObj = new StartButton;
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj, OBJECT_GROUP::PRESSBUTTON);
}

void StartScene::Update()
{
}

void StartScene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void StartScene::Release()
{
}
