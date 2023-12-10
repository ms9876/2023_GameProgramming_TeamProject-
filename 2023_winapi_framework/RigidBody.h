#pragma once

class Object;

class RigidBody
{
	Object* m_pOwner;

	Vec2 _force;			// ũ��, ����
	Vec2 _accel;			// ���ӵ� 
	Vec2 _accelAlpha;	// �߰� ���ӵ�
	Vec2 _velocity;			// �ӵ� 
	Vec2 _maxVelocity;		// �ִ� �ӵ� 

	float	_mass;			// ����

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

	// ������ �� ��� �ӷ��� ���� �Լ�
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

