#include "stdafx.h"
#include "ResourceMgr.h"


ResourceMgr::ResourceMgr()
{
}


ResourceMgr::~ResourceMgr()
{
}

Texture * ResourceMgr::CreateTextureFromFile(std::wstring fileName)
{
	if (!textureMap.count(fileName))
	{
		auto texture = new Texture();

		if (!texture->Init(fileName))
			return nullptr;

		textureMap[fileName] = texture;
	}

	return textureMap[fileName];
}

