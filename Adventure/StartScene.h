#pragma once
class StartScene : public Scene
{
public:
	StartScene();
	~StartScene();

	bool Init();
	void Update(float deltaTime);
	void Render();

};