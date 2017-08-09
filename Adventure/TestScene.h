#pragma once
class TestScene : public Scene
{
public:
	TestScene();
	~TestScene();

	bool Init();
	void Update(float deltaTime);
	void Render();
};

