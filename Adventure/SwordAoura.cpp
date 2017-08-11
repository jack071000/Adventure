#include "stdafx.h"
#include "SwordAoura.h"


SwordAoura::SwordAoura()
{
}


SwordAoura::~SwordAoura()
{
}

bool SwordAoura::Init()
{
	aoura = Sprite::Create(L"Resources/Attack.png");
	aoura->Setrect = true;

	// 162
	// 190

	// 162 * 3
	// 0

	RECT rect;
	SetRect(&aoura->m_Rect,0, 0, 199, 209);

	this->value = 0;

	AddChild(aoura);

	return true;
}
bool b = 0;

void SwordAoura::Update(float deltaTime)
{
	GameObject::Update(deltaTime);

	RECT rect;
	SetRect(&aoura->m_Rect, value, 0, value + 199, 209);

	if (GameTime::TotalFrame % 6 == 0)
		value += 199;

	if (value > 199 * 5)
		Destroy();
	
}

void SwordAoura::Render()
{
	GameObject::Render();
}
