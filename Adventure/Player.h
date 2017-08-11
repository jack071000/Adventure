#pragma once
class SwordAoura;
class Player : public GameObject
{
private:
	static Player* m_instance;

	SwordAoura * Aoura;

	int HP;
	int Attack;
	int Energy;

	Sprite* zeldaStand;
	Sprite* zeldaAttack;

	Sprite* attack;

	int value;

	int AttackTurm;

	//static Player* GetInstance();
	//static void ReleaseInstance();

public:
	Player();
	~Player();

	bool Init();
	void Update(float deltaTime);
	void Render();

	void Moving();
};

