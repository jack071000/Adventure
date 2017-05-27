#pragma once
#define WIN32_LEAN_AND_MEAN
#pragma comment(linker, "/ENTRY:WinMainCRTStartup /SUBSYSTEM:CONSOLE")

#if _DEBUG 
#define WINDOW_MODE 1
#else
#define WINDOW_MODE 0
#endif

#define SAFE_DELETE(x) if(x) {delete x; x = nullptr;}
#define SAFE_RELEASE(x) if(x) {x->Release(); x = nullptr;}

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

#include"GameObject.h"
#include"Scene.h"