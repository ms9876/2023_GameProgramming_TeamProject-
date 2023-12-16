#pragma once
#include "Scene.h"
class SubSceneOne :
    public Scene
{
public:
    SubSceneOne();
    ~SubSceneOne();

public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC _dc) override;

private:
    struct Circle {
        Vec2 position   ;
        float radius;
        bool visible;
    };

    Circle m_circles[10];
    int m_score;
    float time;

    bool IsMouseClickInsideCircle(const Circle& circle) const;
};

