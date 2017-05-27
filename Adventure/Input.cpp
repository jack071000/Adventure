#include "stdafx.h"
#include "Input.h"

Input::Input()
{
	ZeroMemory(m_PrevKeyState, sizeof(m_PrevKeyState));
	ZeroMemory(m_NowKeyState, sizeof(m_NowKeyState));
}
Input::~Input()
{
}

void Input::Update()
{
	UpdateKeyState();
}

void Input::Clear()
{
	// Ű �Է� ���� �ʱ�ȭ
	for (int i = 0; i < 256; i++)
	{
		m_NowKeyState[i] = false;
	}
}

KeyState Input::GetKeyState(int key)
{
	bool prevState = m_PrevKeyState[key];
	bool nowState = m_NowKeyState[key];

	if (prevState == false && nowState == true)
	{
		return KEY_DOWN;
	}
	else if (prevState == true && nowState == true)
	{
		return KEY_PRESS;
	}
	else if (prevState == true && nowState == false)
	{
		return KEY_UP;
	}

	return KEY_NOTPRESS;
}

void Input::UpdateKeyState()
{
	for (int i = 0; i < 256; i++)
	{
		m_PrevKeyState[i] = m_NowKeyState[i];
		m_NowKeyState[i] = static_cast<bool>(::GetKeyState(i) & 0x8000);
	}
}
