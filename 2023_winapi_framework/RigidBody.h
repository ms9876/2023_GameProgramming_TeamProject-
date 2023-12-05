#pragma once

class Object;

class RigidBody
{
	Object* m_pOwner;

	Vec2 _force;			// 크기, 방향
	Vec2 _accel;			// 가속도 
	Vec2 _accelAlpha;	// 추가 가속도
	Vec2 _velocity;			// 속도 
	Vec2 _maxVelocity;		// 최대 속도 

	float	_mass;			// 질량

public:
	RigidBody();
	~RigidBody();

public:
	void Update();

public:
	void AddForce(Vec2 force)
	{
		_force += force;
	}

	// 움직일 때 즉시 속력을 위한 함수
	void AddVelocity(Vec2 velocity) { _velocity = velocity; }

public:
	float GetMass() { return _mass; }
	void SetVelocity(Vec2 velocity) { _velocity = velocity; }
	void SetMaxVelocity(Vec2 maxVelocity) { _maxVelocity = maxVelocity; }
	void SetAccelAlpha(Vec2 accelAlpha) { _accelAlpha = accelAlpha; }

public:
	Vec2 GetVelocity() { return _velocity; }
	Vec2 GetMaxVelocity() { return _maxVelocity; }
	float GetSpeed() { return _velocity.Length(); }

};

