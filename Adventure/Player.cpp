#include "stdafx.h"
#include "Player.h"
#include"SwordAoura.h"

enum class ZeldatState
{
	Stand=1,
	ATTACK,
};

auto state = ZeldatState::Stand;

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

bool plus = 1;

bool Player::Init()
{
	zeldaAttack = Sprite::Create(L"Resources/ZeldaAttack.png");
	zeldaAttack->Setrect = true;

	zeldaStand = Sprite::Create(L"Resources/ZeldaStand.png");
	zeldaStand->Setrect = true;
	//
	Position.x += 500;
	Position.y += 410;
	//
	RECT rect;
	SetRect(&rect, 0, 0, 100, 119);
	zeldaAttack->m_Rect = rect;
	zeldaStand->m_Rect = rect;
	//
	state = ZeldatState::Stand;

	this->value = 0;
	AttackTurm = 0;

	AddChild(zeldaAttack);
	AddChild(zeldaStand);

	return true;
}

void Player::Update(float deltaTime)
{
	GameObject::Update(deltaTime);

	if (state == ZeldatState::ATTACK)
	{
		zeldaAttack->SetVisible(1);
		zeldaStand->SetVisible(0);

		if (GameTime::TotalFrame % 6 == 0)
			value += 113;

		if (value > 325)
		{
			value = 0;
			state = ZeldatState::Stand;
		}

		RECT rect;
		SetRect(&rect, value, 0, value+113, 119);
		zeldaAttack->m_Rect = rect;
	}
		//
		
	if (Input::GetInstance()->GetKeyState(VK_SPACE) == KeyState::KEY_UP & AttackTurm <= 0)
	{
		AttackTurm = 30;

		value = 0;
		auto aoura = new SwordAoura();
		aoura->Init();
		aoura->Position = { -150,-20 };

		AddChild(aoura);
		state = ZeldatState::ATTACK;

	}

	if (state == ZeldatState::Stand)
	{
		zeldaStand->SetVisible(1);
		zeldaAttack->SetVisible(0);
		if (GameTime::TotalFrame % 60 == 0)
			value += 113;

		if (value > 216)
			value = 0;

		RECT rect;
		SetRect(&rect, value, 0, value+100, 120);

		zeldaStand->m_Rect = rect;
	}
	

	Moving();

	printf("VALUE : %d\n", value);

	printf("P.x : %d \n", Position.x);

	AttackTurm--;

}

void Player::Render()
{
	GameObject::Render();
}

void Player::Moving()
{
	if (Singleton<Input>::GetInstance()->GetKeyState(VK_RIGHT) == KeyState::KEY_PRESS)
		Position.x += 3.f;

	if (Singleton<Input>::GetInstance()->GetKeyState(VK_LEFT) == KeyState::KEY_PRESS)
		Position.x -= 3.f;
}
