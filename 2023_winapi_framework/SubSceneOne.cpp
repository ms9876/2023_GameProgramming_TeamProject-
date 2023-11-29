#include "pch.h"
#include "SubSceneOne.h"
#include "JumpMap_B.h"
#include "Core.h"
#include "MyPlayer_JumpMap.h"

void SubSceneOne::Init()
{
	Object* mainMap_B = new JumpMap_B;
	mainMap_B->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 10, Core::GetInst()->GetResolution().y / 10 })));
	mainMap_B->SetScale(Vec2(100.f, 100.f));
	AddObject(mainMap_B, OBJECT_GROUP::MAP);

	Object* myPlayer_W = new MyPlayer_JumpMap;
	myPlayer_W->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	myPlayer_W->SetScale(Vec2(100.f, 100.f));
	AddObject(myPlayer_W, OBJECT_GROUP::PLAYER);
}

void SubSceneOne::Update()
{
	Scene::Update();
}

void SubSceneOne::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void SubSceneOne::Release()
{
}
