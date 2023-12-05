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
	// ���� ���� ũ��
	float force = _force.Length();

	if (0.f != force)
	{
		// ����
		_force.Normalize();

		float accel = force / _mass;

		_accel = _force * accel;
	}

	_accel += _accelAlpha; // �߰� ���ӵ��� ���Ѵ�.


	// �ִ�ӵ� ���� (�ӵ� ���� �˻�)
	if (abs(_maxVelocity.x) < abs(_velocity.x))
	{
		_velocity.x = (_velocity.x / abs(_velocity.x)) * abs(_maxVelocity.x);
	}

	if (abs(_maxVelocity.y) < abs(_velocity.y))
	{
		_velocity.y = (_velocity.y / abs(_velocity.y)) * abs(_maxVelocity.y);
	}

	// �� �ʱ�ȭ
	_force = Vec2(0.f, 0.f);

	// �߰� ���ӵ� ������ �ʱ�ȭ
	_accelAlpha = Vec2(0.f, 0.f);

	// ���ӵ� �ʱ�ȭ
	_accel = Vec2(0.f, 0.f);
}
