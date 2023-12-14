#include "pch.h"
#include "MainScene_W.h"
#include "MainMap_W.h"
#include "Core.h"
#include "MyPlayer_B.h"
#include "PosManager.h"
#include "ResMgr.h"

void MainScene_W::Init()
{
	PosManager::GetInst()->SetBool(true);

	Object* mainMap_W = new MainMap_W; // Èò»ö¸Ê
	mainMap_W->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 10, Core::GetInst()->GetResolution().y / 10 })));
	mainMap_W->SetScale(Vec2(100.f, 100.f));
	AddObject(mainMap_W, OBJECT_GROUP::MAP);

	Object* myPlayer_B = new MyPlayer_B; // °ËÁ¤»ö ÇÃ·¹ÀÌ¾î
	myPlayer_B->SetPos(PosManager::GetInst()->GetPos_B());
	myPlayer_B->SetScale(Vec2(15.f, 15.f));
	AddObject(myPlayer_B, OBJECT_GROUP::PLAYER);

	ResMgr::GetInst()->LoadSound(L"Button", L"Sound\\MP_Tiny-Button-Push.wav", false);
}

void MainScene_W::Update()
{
	Scene::Update();
}

void MainScene_W::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void MainScene_W::Release()
{
	Scene::Release();
}
