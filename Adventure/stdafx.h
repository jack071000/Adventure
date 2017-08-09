#pragma once
#define WIN32_LEAN_AND_MEAN
#pragma comment(linker, "/ENTRY:WinMainCRTStartup /SUBSYSTEM:CONSOLE")

#if _DEBUG 
#define WINDOW_MODE 1
#else
#define WINDOW_MODE 0
#endif

#if _DEBUG
#include<crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#define SAFE_DELETE(x) if(x) {delete x; x = nullptr;}
#define SAFE_RELEASE(x) if(x) {x->Release(); x = nullptr;}

inline bool IsInWindow(float x, float y)
{
	if (x > 0.f && x < 1280.f && y > 0 && y < 720.f)
		return true;
	else
		return false;
}


#include <Windows.h>
#include <stdio.h>
#include <math.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <assert.h>
#include <queue>

#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <time.h>

#include"Singleton.h"
#include"Application.h"
#include"Renderer2D.h"
#include"SceneDirector.h"
#include"GameTime.h"
#include"ResourceMgr.h"
#include"Input.h"


#include"GameObject.h"
#include"Scene.h"
#include"Texture.h"
#include"Sprite.h"
#include"Animation.h"
