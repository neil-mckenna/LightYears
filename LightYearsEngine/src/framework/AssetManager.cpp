#include "framework/AssetManager.h"
#include "framework/Core.h"

using namespace std;

namespace ly
{

	unique<AssetManager> AssetManager::assetManager{ nullptr };

	// singleton
	AssetManager& AssetManager::Get()
	{
		if (!assetManager)
		{
			assetManager = move(unique<AssetManager>{new AssetManager});
		}

		return *assetManager;
	}

	// constructor
	AssetManager::AssetManager() : m_rootDirectory{""}
	{
	}

	shared<Texture> AssetManager::LoadTexture(const string& path)
	{

		auto found = m_LoadedTextureMap.find(path);
		if (found != m_LoadedTextureMap.end())
		{
			return found->second;
		}

		shared<Texture> newTexture{ new Texture };
		// return a texture
		if (newTexture->loadFromFile(m_rootDirectory + path))
		{
			m_LoadedTextureMap.insert({ path, newTexture });
			return newTexture;
		}
		// texture not found
		return shared<Texture>{nullptr};

	}
	void AssetManager::CleanCycle()
	{
		for (auto iter = m_LoadedTextureMap.begin(); iter != m_LoadedTextureMap.end();)
		{
			if (iter->second.unique())
			{
				LOG("Cleaning Textures: %s ", iter->first.c_str());
				iter = m_LoadedTextureMap.erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}

	void AssetManager::SetAssetRootDirectory(const string& directory)
	{
		m_rootDirectory = directory;

	}
}

