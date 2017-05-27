#include "stdafx.h"
#include "StartScene.h"
#include"Player.h"

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

	AddChild(player);

	return true;
}

void StartScene::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
}

void StartScene::Render()
{
	GameObject::Render();
}
