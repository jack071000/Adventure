﻿#include "stdafx.h"
#include "Sprite.h"


Sprite::Sprite()
{
}


Sprite::~Sprite()
{
}

bool Sprite::Init(std::wstring fileName)
{
	if FAILED(D3DXCreateSprite(Singleton<Renderer2D>::GetInstance()->Device, &D3DSprite))
		return false;

	Texture = Singleton<ResourceMgr>::GetInstance()->CreateTextureFromFile(fileName);

	if (Texture == nullptr)
	{
		assert(!"Texture 불러오기 실패");
		return false;
	}

	D3DXVECTOR3 center(Texture->Size.x / 2, Texture->Size.y / 2, 0.f);
	this->Center = center;

	return true;
}

void Sprite::Release()
{
	SAFE_RELEASE(D3DSprite);
}

void Sprite::Update(float deltaTime)
{
	if (!visible)
		return;

	GameObject::Update(deltaTime);
}

void Sprite::Render()
{
	if (!visible)
		return;

	GameObject::Render();

	RECT srcRect;
	SetRect(&srcRect, 0, 0, static_cast<int>(Texture->Size.x), static_cast<int>(Texture->Size.y));

	D3DSprite->Begin(D3DXSPRITE_ALPHABLEND);
	D3DSprite->SetTransform(&Matrix);
	D3DSprite->Draw(Texture->D3DTexture, &srcRect, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
	D3DSprite->End();
}

Sprite * Sprite::Create(std::wstring filename)
{
	auto instance = new Sprite();
	instance->Init(filename);

	return instance;
}
