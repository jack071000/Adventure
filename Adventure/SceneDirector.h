#pragma once
class Scene;
class SceneDirector : public Singleton<SceneDirector>
{
public:
	Scene * CurrentScene;

	friend class Singleton<SceneDirector>;

public:
	SceneDirector();
	~SceneDirector();

	bool ChangeScene(Scene* newScene);

	void Update(float deltaTime);
	void Render();

};

