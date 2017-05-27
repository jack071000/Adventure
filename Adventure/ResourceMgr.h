#pragma once
class Texture;
class ResourceMgr
{
public:
private:
	std::unordered_map<std::wstring, Texture*> textureMap;

public:
	ResourceMgr();
	~ResourceMgr();

	Texture* CreateTextureFromFile(std::wstring fileName);

};

