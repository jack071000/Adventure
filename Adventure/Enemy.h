#pragma once
enum class EnemyDirection
{
	None = 1,
	Left,
	Right,
	Up,
	Down
};
enum class EnemyState
{
	Idle = 1,
	Move,
	Attack
};
class Enemy : public GameObject
{
protected:
	int m_Health;
	float m_Speed;
	float m_Radius;
	int Frame;
	EnemyDirection m_Direction;
	EnemyState m_State;

public:
	Enemy();
	~Enemy();

	virtual bool Init(D3DXVECTOR2 pos);
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Move();
	virtual void Attack();
};