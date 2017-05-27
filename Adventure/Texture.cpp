#include "stdafx.h"
#include "Texture.h"


Texture::Texture() : Size(0.0f, 0.0f)
{
}

Texture::~Texture()
{
}

bool Texture::Init(std::wstring fileName)
{
	HRESULT hr;
	hr = D3DXCreateTextureFromFileEx(
		Singleton<Renderer2D>::GetInstance()->Device,
		fileName.c_str(),
		D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2,
		1, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, NULL, NULL, NULL,
		&D3DTexture
	);

	if FAILED(hr)
	{
		assert(!"Texture ���� ����");
		return false;
	}

	D3DSURFACE_DESC desc;
	if FAILED(D3DTexture->GetLevelDesc(0, &desc))
	{
		assert(!"Texture ���� �������� ����");
		return false;
	}

	Size.x = static_cast<float>(desc.Width);
	Size.y = static_cast<float>(desc.Height);

	return true;
}

void Texture::Release()
{
	SAFE_RELEASE(D3DTexture);
}