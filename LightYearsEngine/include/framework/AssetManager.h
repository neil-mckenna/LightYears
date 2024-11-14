#pragma once

#include <SFML/Graphics.hpp>
#include "framework/Core.h"

using namespace sf;
using namespace std;

namespace ly
{
	class AssetManager
	{
	public:
		static AssetManager& Get();

		shared<Texture> LoadTexture(const string& path);
		void CleanCycle();

	protected:
		AssetManager();

	private:
		static unique<AssetManager> assetManager;
		Dictionary<string, shared<Texture>> m_LoadedTextureMap;
	};




}