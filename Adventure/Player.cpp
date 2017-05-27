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
	
	return true;
}

void Player::Update(float deltaTime)
{
}

void Player::Render()
{
}
