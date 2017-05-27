#pragma once
class Renderer2D : public Singleton<Renderer2D>
{
public:
	LPDIRECT3D9 Direct3D;
	LPDIRECT3DDEVICE9 Device;

	friend class Singleton<Renderer2D>;

public:
	Renderer2D();
	~Renderer2D();

public:
	bool Init(HWND handle, int width, int height, bool windowmode);

	void Release();
	void Begin();
	void End();
};