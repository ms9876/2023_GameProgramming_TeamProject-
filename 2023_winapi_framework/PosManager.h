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
	const Vec2& GetPos_B() const
	{
		return Pos_B;
	}
	const Vec2& GetPos_W() const
	{
		return Pos_W;
	}

private:
	Vec2 Pos_B; // ������ �÷��̾� ��ġ
	Vec2 Pos_W; // ��� �÷��̾� ��ġ
};

