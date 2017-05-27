#include "stdafx.h"
#include "SceneDirector.h"

SceneDirector::SceneDirector() : CurrentScene(nullptr)
{
}


SceneDirector::~SceneDirector()
{
}

bool SceneDirector::ChangeScene(Scene * newScene)
{
	if (CurrentScene)
	{
		CurrentScene->Release();
		delete CurrentScene;
	}
	
	CurrentScene = newScene;
	return CurrentScene->Init();
}

void SceneDirector::Update(float deltaTime)
{
	if (CurrentScene == nullptr)
		return;

	CurrentScene->Update(deltaTime);
}

void SceneDirector::Render()
{
	if (CurrentScene == nullptr)
		return;

	CurrentScene->Render();
}
