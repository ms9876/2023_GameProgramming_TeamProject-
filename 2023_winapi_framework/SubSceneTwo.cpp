#include "pch.h"
#include "SubSceneTwo.h"
#include "SubTwoMap.h"
#include "Core.h"

void SubSceneTwo::Init()
{
	Object* map = new SubTwoMap;
	//map->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 10, Core::GetInst()->GetResolution().y / 10 })));
	//map->SetScale(Vec2(100.f, 100.f));
	AddObject(map, OBJECT_GROUP::MAP);
}

void SubSceneTwo::Update()
{
	Scene::Update();
}

void SubSceneTwo::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void SubSceneTwo::Release()
{
	Scene::Release();
}
