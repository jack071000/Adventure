#include "stdafx.h"
#include "TestScene.h"


TestScene::TestScene()
{
}


TestScene::~TestScene()
{
}

bool TestScene::Init()
{
	D3DXVECTOR3 v7(3.0f, 0.0f, 0.f);
	D3DXVECTOR3 v8(-3.0f,0.f, 0.f);
	float fCos, fDot, fScale;

	fDot = D3DXVec3Dot(&v7, &v8);
	fScale = D3DXVec3Length(&v7) * D3DXVec3Length(&v8);
	fCos = fDot / fScale;

	printf("¶óµð¾È : %f", fCos);


	return true;
}

void TestScene::Update(float deltaTime)
{
	Scene::Update(deltaTime);
}

void TestScene::Render()
{
	Scene::Render();
}
