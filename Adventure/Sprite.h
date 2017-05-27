#pragma once
class Sprite : public GameObject
{
public:
	LPD3DXSPRITE D3DSprite;
	Texture* Texture;

	D3DXVECTOR3 Center;

	RECT m_Rect;

	bool Setrect;

public:
	Sprite();
	virtual ~Sprite();

	bool Init(std::wstring fileName);

	void Release();

	virtual void Update(float deltaTime);

	virtual void Render();

	static Sprite* Create(std::wstring filename);
};

