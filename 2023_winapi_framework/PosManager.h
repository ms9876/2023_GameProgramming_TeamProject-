#pragma once
#include "define.h"
#include "Core.h"
class PosManager
{
	SINGLE(PosManager);
public:
	void Init();
	void SetPos_B(Vec2 vec) { Pos_B = vec; }
	void SetPos_W(Vec2 vec) { Pos_W = vec; }
	void SetBool(bool b) { IsblackMap = b; }
	const Vec2& GetPos_B() const
	{
		return Pos_B;
	}
	const Vec2& GetPos_W() const
	{
		return Pos_W;
	}
	const bool& GetBool() const
	{
		return IsblackMap;
	}

private:
	Vec2 Pos_B; // 검정색 플레이어 위치
	Vec2 Pos_W; // 흰색 플레이어 위치

	bool IsblackMap;

public:
	// 검정색 플레이어 각 버튼 마다 위치
	Vec2 Green_B;
	Vec2 Blue_B;
	Vec2 Yellow_B;
	Vec2 LimeGreen_B;
	Vec2 LightPink_B;
	Vec2 LightYellow_B;
	Vec2 Gray_B;
	Vec2 LightBrown_B;
	Vec2 Red_B;
	Vec2 SkyBlue_B;
	Vec2 Purple_B;

	// 흰색 플레이어 각 버튼 마다 위치
	Vec2 Green_W;
	Vec2 Blue_W;
	Vec2 Yellow_W;
	Vec2 LimeGreen_W;
	Vec2 LightPink_W;
	Vec2 LightYellow_W;
	Vec2 Gray_W;
	Vec2 LightBrown_W;
	Vec2 Red_W;
	Vec2 SkyBlue_W;
	Vec2 Purple_W;
};

