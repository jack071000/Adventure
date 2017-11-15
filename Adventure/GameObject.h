#pragma once
enum class Tag
{
	Player = 0,
	Enemy
};


class GameObject
{
public:
	GameObject* Parent;
	std::vector<GameObject*> Children;
	std::queue<GameObject*> Garbage;

	std::string Name;
	float Rotation;

	Tag m_Tag;

	D3DXVECTOR2 Position;
	D3DXMATRIX Matrix;
	D3DXVECTOR2 Scale;

	D3DXVECTOR2 ScaleCenter;

	bool visible;
	bool UseParentMatrix;

public:
	GameObject();
	virtual ~GameObject();

	virtual bool Init();
	virtual void Release();
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Destroy()
	{
		if (Parent)
			Parent->Garbage.push(this);
	}


public:
	void AddChild(GameObject* child);
	void RemoveChild(GameObject * child, bool memoryDelete);
	void SetVisible(bool visible)
	{
		this->visible = visible;
	}

};

