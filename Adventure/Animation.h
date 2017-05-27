#pragma once
class Sprite;
class Animation : public Sprite
{
public:
	std::vector<Sprite*> SpriteList;

	int FrameCounter;
	int FrameDelay;
	int LastFrame;
	int CurrentFrame;

public:
	Animation();
	~Animation();

	int GetFrameDelay() { return FrameDelay; }
	void SetFrameDelay(int frame) { FrameDelay = frame; }

	void AddFrame(std::wstring fileName);

public:
	void Update(float deltaTime);
	void Render();
};

