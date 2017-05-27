#pragma once

enum KeyState
{
	KEY_NOTPRESS,
	KEY_DOWN,
	KEY_PRESS,
	KEY_UP
};

class Input : public Singleton<Input>
{
private:
	bool m_PrevKeyState[256];
	bool m_NowKeyState[256];


public:
	Input();
	~Input();

	void Update();

	void Clear();

public:
	KeyState GetKeyState(int key);

private:
	void UpdateKeyState();


};