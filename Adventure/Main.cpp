#include"stdafx.h"
#include"StartScene.h"
#include"TestScene.h"
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc( );
	
#endif
	Application* App = Singleton<Application>::GetInstance();
	//D3DXMatrixIdentity(&GameObject::CameraMatrix);

	App->Init(L"Adventure", 1280, 720, 1);

	Singleton<SceneDirector>::GetInstance()->ChangeScene(new StartScene());

	App->Run();
	App->Release();
}