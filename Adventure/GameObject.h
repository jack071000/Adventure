#pragma once
class GameObject
{
public:
	GameObject* Parent;
	std::vector<GameObject*> Children;
	
	std::string Name;
	float Rotation;

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

public:
	void AddChild(GameObject* child);
	void RemoveChild(GameObject * child, bool memoryDelete);


};

