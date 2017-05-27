#include "stdafx.h"
#include "Animation.h"


Animation::Animation() : FrameCounter(0) , FrameDelay(0)
{
}

Animation::~Animation()
{
}

void Animation::AddFrame(std::wstring fileName)
{
	auto spriteFrame = Sprite::Create(fileName);
	spriteFrame->Parent = this;

	SpriteList.push_back(spriteFrame);
}

void Animation::Update(float deltaTime)
{
	GameObject::Update(deltaTime);

	FrameCounter++;

	if (FrameCounter >= FrameDelay)
	{
		FrameCounter = 0;
		CurrentFrame++;
	}
	
	if (CurrentFrame > (SpriteList.size() - 1))
		CurrentFrame = 0;

	SpriteList.at(CurrentFrame)->Update(deltaTime);
}

void Animation::Render()
{
	GameObject::Render();

	if (!visible)
		return;

	SpriteList.at(CurrentFrame)->Render();
}