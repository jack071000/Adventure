#include "stdafx.h"
#include "Renderer2D.h"


Renderer2D::Renderer2D()
{
}


Renderer2D::~Renderer2D()
{
}

bool Renderer2D::Init(HWND handle, int width, int height, bool windowmode)
{
	if ((Direct3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
	{
		assert(!"Direct3D ���� ����");
		return false;
	}

	D3DPRESENT_PARAMETERS pp = {};
	pp.BackBufferWidth = width;
	pp.BackBufferHeight = height;
	pp.BackBufferFormat = D3DFMT_A8R8G8B8;
	pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	pp.hDeviceWindow = handle;
	pp.Windowed = windowmode;

	HRESULT hr;
	hr = Direct3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, handle,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pp, &Device);

	if FAILED(hr)
	{
		assert(!"Device ���� ����");
		return false;
	}
	switch (hr)
	{
	case D3DERR_INVALIDCALL:
		printf("�޼����� ȣ���� ��ȿ�̴�. ���� ���, �޼����� �Ķ���Ϳ� ��ȿ�� ���� �����Ǿ� �ִ� ��� ���̴�");
		break;
	case D3DERR_NOTAVAILABLE:
		printf("�� ��ġ��, ������ ��ũ���� ���� �ϰ� ���� �ʴ�.");
		break;
	case D3DERR_OUTOFVIDEOMEMORY:
		printf("Direct3D �� ó���� �ǽ��ϴµ� ����� ���÷��� �޸𸮰� ����.");
		break;
	case D3D_OK:
		break;
	default:
		printf("��� �׸񿡵� �ش�x");
	}
	return true;
}

void Renderer2D::Release()
{
}

void Renderer2D::Begin()
{
	Device->BeginScene();
	Device->Clear(1.0f, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(100, 100, 100), 1.0f, 0);
}

void Renderer2D::End()
{
	Device->EndScene();
	Device->Present(NULL, NULL, NULL, NULL);
}