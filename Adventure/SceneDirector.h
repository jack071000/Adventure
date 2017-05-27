#pragma once
class Scene;
class SceneDirector
{
public:
	Scene * CurrentScene;

public:
	SceneDirector();
	~SceneDirector();

	bool ChangeScene(Scene* newScene);

	void Update(float deltaTime);
	void Render();

};

