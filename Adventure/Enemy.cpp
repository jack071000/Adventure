#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy()
	:m_Health(1)
	, m_Speed(1.f)
	, m_Radius(0.f)
{
	m_State = EnemyState::Idle;
	m_Direction = EnemyDirection::None;
	m_Tag = Tag::Enemy;
}
Enemy::~Enemy()
{
}
bool Enemy::Init(D3DXVECTOR2 pos)
{
	//Animation Init
	//m_Size = Animation->size
	//BoxCollider::Create(pos,m_size);
	//EnemyName Init
	//AddChild(Anim);
	return true;
}
void Enemy::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
}
void Enemy::Render()
{
	GameObject::Render();
}
void Enemy::Move()
{
}
void Enemy::Attack()
{
}