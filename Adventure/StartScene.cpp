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

	return true;
}

void StartScene::Update(float deltaTime)
{
	Scene::Update(deltaTime);
}

void StartScene::Render()
{
	Scene::Render();
}
