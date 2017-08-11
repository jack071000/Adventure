#include "stdafx.h"
#include "StartScene.h"
#include"Player.h"
#include"SwordAoura.h"
D3DXMATRIX StartScene::CameraMatrix;
float StartScene::CameraX = 0.0f;
float StartScene::CameraY = 0.0f;

bool a = true;

StartScene::StartScene()
{
}


StartScene::~StartScene()
{
}

bool StartScene::Init()
{
	player = new Player();
	player->Init();

	

	bok = Sprite::Create(L"Resources/Monster.png");
	bok->Position = { 300, 310 };
	
	printf("bok : %f , bok : %f", bok->Center.x, bok->Center.y);

	auto map = Sprite::Create(L"Resources/Map.png");
	
	AddChild(map);
	AddChild(player);
	AddChild(bok);
	

	return true;
}

void StartScene::Update(float deltaTime)
{
	GameObject::Update(deltaTime);

	if (Input::GetInstance()->GetKeyState('O'))
	{
		Position.x -= 5.f;
	}

	if (Input::GetInstance()->GetKeyState('P'))
	{
		Position.x += 5.f;
	}

	if (Input::GetInstance()->GetKeyState('1'))
	{
		Scale += {0.01f, 0.01f};
	}

	if (Input::GetInstance()->GetKeyState('2'))
	{
		Rotation += 1.f;
	}

	if (Input::GetInstance()->GetKeyState('3'))
	{
		bok->Scale += {0.01f, 0.01f};
	}

	if (Input::GetInstance()->GetKeyState('4'))
	{
		bok->Rotation += 1.f;
	}

	if (Input::GetInstance()->GetKeyState('5'))
	{
		bok->Position.x += 1.f;
	}
	
	if (Input::GetInstance()->GetKeyState('6'))
	{
		bok->Position.x -= 1.f;
	}
}

void StartScene::Render()
{
	GameObject::Render();
}
