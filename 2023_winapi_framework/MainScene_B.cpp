#include "pch.h"
#include "MainScene_B.h"
#include "MainMap_B.h"
#include "Core.h"
#include "MyPlayer_W.h"
#include "PosManager.h"

void MainScene_B::Init()
{
	Object* mainMap_B = new MainMap_B; // °ËÁ¤»ö ¸Ê
	mainMap_B->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 10, Core::GetInst()->GetResolution().y / 10 })));
	mainMap_B->SetScale(Vec2(100.f, 100.f));
	AddObject(mainMap_B, OBJECT_GROUP::MAP);

	Object* myPlayer_W = new MyPlayer_W; // Èò»ö ÇÃ·¹ÀÌ¾î
	myPlayer_W->SetPos(PosManager::GetInst()->GetPos_W());
	myPlayer_W->SetScale(Vec2(15.f, 15.f));
	AddObject(myPlayer_W, OBJECT_GROUP::PLAYER);
}

void MainScene_B::Update()
{
	Scene::Update();
}

void MainScene_B::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void MainScene_B::Release()
{
	Scene::Release();
}
