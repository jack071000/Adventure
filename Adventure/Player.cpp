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

	Position.x += 500;
	Position.y += 300;

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

	if (Singleton<Input>::GetInstance()->GetKeyState(VK_SPACE) == KeyState::KEY_PRESS)
	{
		if (GameTime::TotalFrame % 3 == 0)
		{
			value += 115;

			if (value > 575)
				value = 0;
		}
	}
	
	RECT rect;
	SetRect(&rect, value, 0, value+100, 120);

	if (Singleton<Input>::GetInstance()->GetKeyState(VK_RIGHT) == KeyState::KEY_PRESS)
	{
		Position.x += 3.f;
	}

	if (Singleton<Input>::GetInstance()->GetKeyState(VK_LEFT) == KeyState::KEY_PRESS)
	{
		Position.x -= 3.f;
	}

	printf("VALUE : %d", value);

	zelda->m_Rect = rect;
}

void Player::Render()
{
	GameObject::Render();
}
