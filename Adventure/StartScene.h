#pragma once
class Player;
class StartScene : public Scene
{
private:
	Sprite* StartSceneBackGround;
	Player* player;

public:
	StartScene();
	~StartScene();

	bool Init();
	void Update(float deltaTime);
	void Render();
};