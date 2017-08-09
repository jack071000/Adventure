#pragma once
class Sprite : public GameObject
{
public:
	LPD3DXSPRITE D3DSprite;
	Texture* Texture;

	D3DXVECTOR2 Center;

	RECT m_Rect;

	bool Setrect;

	bool IsFlipX;

public:
	Sprite();
	virtual ~Sprite();

	bool Init(std::wstring fileName);

	void Release();

	virtual void Update(float deltaTime);

	virtual void Render();

	void FlipX();

	static Sprite* Create(std::wstring filename);


};

