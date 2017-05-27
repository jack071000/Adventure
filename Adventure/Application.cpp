#include "stdafx.h"
#include "Application.h"


Application::Application()
{
}


Application::~Application()
{
}

bool Application::Init(std::wstring title, int width, int height, bool windowmode)
{
	Title = title;
	Width = width;
	Height = height;
	windowMode = windowmode;

	_CreateWindow(Title, Width, Height, windowMode);
	_Create2DRenderer();

	return true;
}

bool Application::_CreateWindow(std::wstring title, int width, int height, bool windowmode)
{
	WNDCLASS wc = {};
	wc.lpszClassName = L"Application";
	wc.lpfnWndProc = WndProc;

	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	if (RegisterClass(&wc) == NULL)
		return 0;

	DWORD style;

	if (windowMode)
		style = WS_OVERLAPPEDWINDOW;
	else
		style = WS_EX_TOPMOST | WS_POPUP;

	m_handle = CreateWindow(wc.lpszClassName, title.c_str(), style, 0, 0, width, height, NULL, NULL, wc.hInstance, NULL);

	if (m_handle == NULL)
		return 0;

	return true;
}

bool Application::_Create2DRenderer()
{
	Singleton<Renderer2D>::GetInstance()->Init(m_handle, Width, Height, windowMode);
	return true;
}

bool Application::Run()
{
	ShowWindow(m_handle, SW_SHOWDEFAULT);

	MSG msg = {};

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				return true;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		else
		{
			//게임 루프
			Singleton<Renderer2D>::GetInstance()->Begin();
			Singleton<Input>::GetInstance()->Update();
			Singleton<SceneDirector>::GetInstance()->Update(16.f);
			Singleton<SceneDirector>::GetInstance()->Render();
			Singleton<Renderer2D>::GetInstance()->End();

			GameTime::CurrentFrame++;
			GameTime::TotalFrame++;

			if (GameTime::CurrentFrame > 60)
				GameTime::CurrentFrame = 0;

		}

	}

	return true;
}

bool Application::Release()
{
	return true;
}

LRESULT Application::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}
