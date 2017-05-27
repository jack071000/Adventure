#pragma once
class StartScene : public Scene
{
private:
	Animation* a;


public:
	StartScene();
	~StartScene();

	bool Init();
	void Update(float deltaTime);
	void Render();

};