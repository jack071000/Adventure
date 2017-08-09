#pragma once
class Player;
class StartScene : public Scene
{
private:
	Sprite* StartSceneBackGround;
	Player* player;

	Sprite* bok;


public:
	StartScene();
	~StartScene();

	bool Init();
	void Update(float deltaTime);
	void Render();

	static D3DXMATRIX CameraMatrix;
	static float CameraX;
	static float CameraY;
};