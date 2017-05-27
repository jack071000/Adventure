#pragma once
template <class T>
class Singleton
{
private:
	static T* instance;

public:
	Singleton()
	{}

	virtual ~Singleton()
	{
		if (instance)
			delete instance;
	}

	static T* GetInstance()
	{
		if (instance == nullptr)
			instance = new T();

		return instance;
	}

	static void ReleaseInstance()
	{
		if (instance != nullptr)
		{
			delete instance;
			instance = nullptr;
		}
	}
};

template <class T>
T* Singleton<T>::instance = nullptr;
