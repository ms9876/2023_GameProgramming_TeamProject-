#include "pch.h"
#include "PosManager.h"

void PosManager::Init()
{
	//IsblackMap = true;
	Pos_W = Vec2({ Core::GetInst()->GetResolution().x / 2 - 125, Core::GetInst()->GetResolution().y / 2 - 200 });

	Green_B = Vec2({ Core::GetInst()->GetResolution().x / 2 - 20, Core::GetInst()->GetResolution().y / 2 - 120 });
	Blue_B = Vec2({ Core::GetInst()->GetResolution().x / 2 + 200, Core::GetInst()->GetResolution().y / 2 + 200 });
	Yellow_B = Vec2({ Core::GetInst()->GetResolution().x / 2 - 70, Core::GetInst()->GetResolution().y / 2 - 197 });
	LimeGreen_B = Vec2({ Core::GetInst()->GetResolution().x / 2 + 27, Core::GetInst()->GetResolution().y / 2 + 20 });
	LightPink_B = Vec2({ Core::GetInst()->GetResolution().x / 2 - 197, Core::GetInst()->GetResolution().y / 2 - 65 });
	LightYellow_B = Vec2({ Core::GetInst()->GetResolution().x / 2 + 150, Core::GetInst()->GetResolution().y / 2 - 197 });
	Gray_B = Vec2({ Core::GetInst()->GetResolution().x / 2 + 200, Core::GetInst()->GetResolution().y / 2 - 190 });
	LightBrown_B = Vec2({ Core::GetInst()->GetResolution().x / 2 - 110, Core::GetInst()->GetResolution().y / 2 + 160 });
	Red_B = Vec2({ Core::GetInst()->GetResolution().x / 2 - 197, Core::GetInst()->GetResolution().y / 2 + 100 });
	SkyBlue_B = Vec2({ Core::GetInst()->GetResolution().x / 2 - 65, Core::GetInst()->GetResolution().y / 2 + 200 });
	Purple_B = Vec2({ Core::GetInst()->GetResolution().x / 2 - 100, Core::GetInst()->GetResolution().y / 2 - 110 });

	Green_W = Vec2({ Core::GetInst()->GetResolution().x / 2 - 150, Core::GetInst()->GetResolution().y / 2 - 123 });
	Blue_W = Vec2({ Core::GetInst()->GetResolution().x / 2 + 50, Core::GetInst()->GetResolution().y / 2 + 166 });
	Yellow_W = Vec2({ Core::GetInst()->GetResolution().x / 2 + 45, Core::GetInst()->GetResolution().y / 2 - 203 });
	LimeGreen_W = Vec2({ Core::GetInst()->GetResolution().x / 2 + 5, Core::GetInst()->GetResolution().y / 2 - 123 });
	LightPink_W = Vec2({ Core::GetInst()->GetResolution().x / 2 - 170, Core::GetInst()->GetResolution().y / 2 - 82 });
	LightYellow_W = Vec2({ Core::GetInst()->GetResolution().x / 2 + 200, Core::GetInst()->GetResolution().y / 2 - 43 });
	Gray_W = Vec2({ Core::GetInst()->GetResolution().x / 2 - 203, Core::GetInst()->GetResolution().y / 2 + 150 });
	LightBrown_W = Vec2({ Core::GetInst()->GetResolution().x / 2 - 163, Core::GetInst()->GetResolution().y / 2 });
	Red_W = Vec2({ Core::GetInst()->GetResolution().x / 2 - 203, Core::GetInst()->GetResolution().y / 2 + 85 });
	SkyBlue_W = Vec2({ Core::GetInst()->GetResolution().x / 2 + 205, Core::GetInst()->GetResolution().y / 2 - 90 });
	Purple_W = Vec2({ Core::GetInst()->GetResolution().x / 2 - 3, Core::GetInst()->GetResolution().y / 2 + 80 });
}
