#include"stdafx.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc( );

#endif
	Singleton<Application>::GetInstance()->Init(L"Adventure", 1280, 720, 0);



}