#pragma once
class SwordAoura : public GameObject
{
public:
	SwordAoura();
	~SwordAoura();

	Sprite* aoura;

	int value;

public:
	bool Init();
	void Update(float deltaTime);
	void Render();

};

