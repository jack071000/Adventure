#pragma once
class Application : public Singleton<Application>
{
private:
	HWND m_handle;
	friend class Singleton<Application>;

public:
	Application();
	~Application();

	int Width;
	int Height;
	std::wstring Title;
	bool windowMode;

public:
	bool Init(std::wstring title, int width, int height, bool windowmode);
	bool _CreateWindow(std::wstring title, int width, int height, bool windowmode);
	bool _Create2DRenderer();

	bool Run();
	bool Release();


private:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

public:


};

