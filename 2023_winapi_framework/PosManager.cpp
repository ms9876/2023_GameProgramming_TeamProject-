#include "pch.h"
#include "PosManager.h"

void PosManager::Init()
{
	Pos_W = Vec2({ Core::GetInst()->GetResolution().x / 2 - 70, Core::GetInst()->GetResolution().y / 2 - 197 });
	//Pos_W = Vec2({ Core::GetInst()->GetResolution().x / 2 - 70, Core::GetInst()->GetResolution().y / 2 - 197 });
}
