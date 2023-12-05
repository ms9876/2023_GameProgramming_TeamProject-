#include "pch.h"
#include "RigidBody.h"
#include "TimeMgr.h"
#include "Object.h"


RigidBody::RigidBody() : 
	m_pOwner(nullptr),
	_maxVelocity(Vec2(200.f, 500.f))
{
}

RigidBody::~RigidBody()
{
}

void RigidBody::Update()
{
	// 순수 힘의 크기
	float force = _force.Length();

	if (0.f != force)
	{
		// 방향
		_force.Normalize();

		float accel = force / _mass;

		_accel = _force * accel;
	}

	_accel += _accelAlpha; // 추가 가속도를 더한다.


	// 최대속도 제한 (속도 제한 검사)
	if (abs(_maxVelocity.x) < abs(_velocity.x))
	{
		_velocity.x = (_velocity.x / abs(_velocity.x)) * abs(_maxVelocity.x);
	}

	if (abs(_maxVelocity.y) < abs(_velocity.y))
	{
		_velocity.y = (_velocity.y / abs(_velocity.y)) * abs(_maxVelocity.y);
	}

	// 힘 초기화
	_force = Vec2(0.f, 0.f);

	// 추가 가속도 누적량 초기화
	_accelAlpha = Vec2(0.f, 0.f);

	// 가속도 초기화
	_accel = Vec2(0.f, 0.f);
}
