#include "pch.h"
#include "SubSceneTwo.h"
#include "SubTwoMap.h"
#include "Core.h"

void SubSceneTwo::Init()
{
	Object* map = new SubTwoMap;
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
