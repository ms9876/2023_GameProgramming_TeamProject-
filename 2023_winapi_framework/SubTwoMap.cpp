#include "pch.h"
#include "SubTwoMap.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "PosManager.h"
#include "SceneMgr.h"
#include "Core.h"

SubTwoMap::SubTwoMap()
	:currentTime(0)
	,changeTime(10.0f)
	,checkTime(0)
	,cantpressTime(0.5f)
	,currentColor(rand() % 7 + 1)
	,pressCount(0)
	,winCount(5)
	,brush(nullptr)
{
	GetClientRect(Core::GetInst()->GetHwnd(), &rect);
}

SubTwoMap::~SubTwoMap()
{
}

void SubTwoMap::Update()
{
	checkTime += fDT;
	currentTime += fDT;
	if (pressCount >= winCount)
	{
		if (PosManager::GetInst()->GetBool() == false)
			SceneMgr::GetInst()->LoadScene(L"MainScene_W");
		else
			SceneMgr::GetInst()->LoadScene(L"MainScene_B");
	}
	else if (currentTime >= changeTime)
	{
		PosManager::GetInst()->Init();
		SceneMgr::GetInst()->LoadScene(L"MainScene_B");
	}

	switch (currentColor)
	{
	case 1:
	{
		brush = Core::GetInst()->GetBrush(BRUSH_TYPE::RED);
		if (KEY_PRESS(KEY_TYPE::R))
		{
			pressCount++;
			currentTime = 0;
			currentColor = rand() % 7 + 1;
		}
	}
	break;
	case 2:
	{
		brush = Core::GetInst()->GetBrush(BRUSH_TYPE::ORANGE);
		if (KEY_PRESS(KEY_TYPE::O))
		{
			pressCount++;
			currentTime = 0;
			currentColor = rand() % 7 + 1;
		}
	}
	break;
	case 3:
	{
		brush = Core::GetInst()->GetBrush(BRUSH_TYPE::YELLOW);
		if (KEY_PRESS(KEY_TYPE::Y))
		{
			pressCount++;
			currentTime = 0;
			currentColor = rand() % 7 + 1;
		}
	}
	break;
	case 4:
	{
		brush = Core::GetInst()->GetBrush(BRUSH_TYPE::GREEN);
		if (KEY_PRESS(KEY_TYPE::G))
		{
			pressCount++;
			currentTime = 0;
			currentColor = rand() % 7 + 1;
		}
	}
	break;
	case 5:
	{
		brush = Core::GetInst()->GetBrush(BRUSH_TYPE::BLUE);
		if (KEY_PRESS(KEY_TYPE::B))
		{
			pressCount++;
			currentTime = 0;
			currentColor = rand() % 7 + 1;
		}
	}
	break;
	case 6:
	{
		brush = Core::GetInst()->GetBrush(BRUSH_TYPE::NAVYBLUE);
		if (KEY_PRESS(KEY_TYPE::N))
		{
			pressCount++;
			currentTime = 0;
			currentColor = rand() % 7 + 1;
		}
	}
	break;
	case 7:
	{
		brush = Core::GetInst()->GetBrush(BRUSH_TYPE::PURPLE);
		if (KEY_PRESS(KEY_TYPE::P))
		{
			pressCount++;
			currentTime = 0;
			currentColor = rand() % 7 + 1;
		}
	}
	break;
	default:
		break;
	}
}

void SubTwoMap::Render(HDC _dc)
{
	FillRect(_dc, &rect, brush);
}
