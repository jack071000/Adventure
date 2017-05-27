#include "stdafx.h"
#include "Player.h"

/*
Player * Player::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new Player();
	}

	return m_instance;
}

void Player::ReleaseInstance()
{
	if (m_instance != nullptr)
	{
		delete m_instance;
		m_instance = nullptr;
	}
}
*/
Player::Player() : HP(2) , Attack(1) , Energy(90)
{
}

Player::~Player()
{
}

bool Player::Init()
{
	zelda = Sprite::Create(L"Resources/Zelda.png");
	zelda->Setrect = true;
	RECT rect;
	SetRect(&rect, 0, 0, 100, 120);
	zelda->m_Rect = rect;
	this->value = 0;
	AddChild(zelda);
	return true;
}

void Player::Update(float deltaTime)
{
	GameObject::Update(deltaTime);

	if (GameTime::TotalFrame % 15 == 0)
	{
		value += 115;

		if (value > 575)
			value = 575;
	}

	RECT rect;
	SetRect(&rect, value, 0, value+100, 120);

	printf("VALUE : %d", value);

	zelda->m_Rect = rect;
}

void Player::Render()
{
	GameObject::Render();
}
