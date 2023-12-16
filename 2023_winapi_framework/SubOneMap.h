#pragma once
class SubOneMap
{
public:
    SubOneMap();
    ~SubOneMap();

public:
    void Update() override;
    void Render(HDC _dc) override;

private:
    struct Circle {
        Vec2 position;
        float radius;
        bool visible;
    };

    Circle m_circles[10];
    int m_score;

    bool IsMouseClickInsideCircle(const Circle& circle) const;
};
};

