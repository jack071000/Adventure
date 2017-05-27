#include"stdafx.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc( );

#endif
	Application* App = Singleton<Application>::GetInstance();

	App->Init(L"Adventure", 1280, 720, 1);
	App->Run();
	App->Release();

}