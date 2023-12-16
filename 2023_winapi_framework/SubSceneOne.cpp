#include "pch.h"
#include "SubSceneOne.h"
#include "Core.h"
#include "KeyMgr.h"
#include "PosManager.h"
#include "SceneMgr.h"
#include "PlayTimeMgr.h"
#include "TimeMgr.h"

SubSceneOne::SubSceneOne() :
    m_score(0)
{
}

SubSceneOne::~SubSceneOne()
{
}

void SubSceneOne::Init()
{
    time = PlayTimeMgr::GetInst()->GetPlayTime();
    for (auto& circle : m_circles) {
        circle.position.y = static_cast<float>(rand() % (400 - 50) + 100);
        circle.position.x = static_cast<float>(rand() % (400 - 50) + 25);
        circle.radius = 25.0f;
        circle.visible = true;
    }
}


void SubSceneOne::Update() {
    time += fDT;
    PlayTimeMgr::GetInst()->SetPlayTime(time);

    if (KEY_PRESS(KEY_TYPE::LBUTTON)) {
        for (auto& circle : m_circles) {
            if (circle.visible && IsMouseClickInsideCircle(circle)) {
                circle.visible = false;
                m_score++;
            }
        }
    }

    if (m_score == 10) {
        if (PosManager::GetInst()->GetBool() == false)
            SceneMgr::GetInst()->LoadScene(L"MainScene_W");
        else
            SceneMgr::GetInst()->LoadScene(L"MainScene_B");
        Init();
        m_score = 0;
    }
    Scene::Update();
}

void SubSceneOne::Render(HDC _dc) {

    wstring s;
    s = std::to_wstring(time);
    TextOut(_dc, 100, 0, s.c_str(), s.length());

    for (const auto& circle : m_circles) {
        if (circle.visible) {
            Ellipse(_dc,
                static_cast<int>(circle.position.x - circle.radius),
                static_cast<int>(circle.position.y - circle.radius),
                static_cast<int>(circle.position.x + circle.radius),
                static_cast<int>(circle.position.y + circle.radius)
            );
        }
    }

    Scene::Render(_dc);
}

bool SubSceneOne::IsMouseClickInsideCircle(const Circle& circle) const {
    POINT mousePos;
    GetCursorPos(&mousePos);
    ScreenToClient(Core::GetInst()->GetHwnd(), &mousePos);

    float distance = sqrt(pow(mousePos.x - circle.position.x, 2) + pow(mousePos.y - circle.position.y, 2));

    return distance < circle.radius;
}
