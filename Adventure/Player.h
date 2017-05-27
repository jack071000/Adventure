#pragma once
class Player : public GameObject
{
private:
	int HP;
	int Attack;
	int Energy;

public:
	Player();
	~Player();

	bool Init();
	void Update(float deltaTime);
	void Render();
};

