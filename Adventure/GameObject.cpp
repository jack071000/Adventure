#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject() : Parent(nullptr) , Rotation(0.f) , visible(1) , UseParentMatrix(1) , Position(0.f,0.f) , Scale(1.f,1.f) , ScaleCenter(0.f,0.f)
{
}


GameObject::~GameObject()
{
}

bool GameObject::Init()
{
	return true;
}

void GameObject::Release()
{
}

void GameObject::Update(float deltaTime)
{
	if (visible == false) return;

	D3DXMatrixTransformation2D(&Matrix, &ScaleCenter, 0.0f, &Scale, NULL, Rotation, &Position);

	if (Parent)
	{
		if (UseParentMatrix)
			Matrix *= Parent->Matrix;
	}
	//
	while (!Garbage.empty())
	{
		RemoveChild(Garbage.front(), true);
		Garbage.pop();
	}


	for (auto child : Children)
		child->Update(deltaTime);



}

void GameObject::Render()
{
	if (visible == false) return;

	//
	for (auto child : Children)
		child->Render();
}

void GameObject::AddChild(GameObject * child)
{
	child->Parent = this;
	Children.push_back(child);
}

void GameObject::RemoveChild(GameObject * child, bool memoryDelete)
{
	auto iterator = std::find(std::begin(Children), std::end(Children), child);
	if (iterator == Children.end())
		return;

	Children.erase(iterator);

	if (memoryDelete)
	{
		child->Release();
		SAFE_DELETE(child);
		return;
	}

	child->Parent = nullptr;
}
