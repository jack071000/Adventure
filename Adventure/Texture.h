#pragma once
class Texture
{
public:
	LPDIRECT3DTEXTURE9 D3DTexture;
	D3DXVECTOR2 Size;

public:
	Texture();
	virtual ~Texture();

	bool Init(std::wstring fileName);

	void Release();
};

