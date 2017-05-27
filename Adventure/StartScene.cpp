#include "stdafx.h"
#include "StartScene.h"


StartScene::StartScene()
{
}


StartScene::~StartScene()
{
}

bool StartScene::Init()
{
	printf("StartScene");

	a = new Animation();
	a->AddFrame(L"Resources/1.png");
	a->AddFrame(L"Resources/2.png");
	a->AddFrame(L"Resources/3.png");

	a->FrameDelay = 60;
	

	AddChild(a);

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
