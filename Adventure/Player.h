#pragma once
class Player : public GameObject
{
private:
	//static Player* m_instance;

	int HP;
	int Attack;
	int Energy;

	//static Player* GetInstance();
	//static void ReleaseInstance();

public:
	Player();
	~Player();

	bool Init();
	void Update(float deltaTime);
	void Render();
};

