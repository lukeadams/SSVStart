// Copyright (c) 2013-2015 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVS_ASSETS_ASSETFOLDER
#define SSVS_ASSETS_ASSETFOLDER

namespace ssvs
{
	class AssetManager;

	class AssetFolder
	{
		private:
			Path rootPath;
			std::vector<Path> files;

			inline std::vector<Path> getFilteredFiles(const std::vector<std::string>& mExtensions)
			{
				std::vector<Path> result;
				for(const auto& f : files) for(const auto& e : mExtensions) if(f.hasExtension(e)) result.emplace_back(f);
				return result;
			}
			inline void loadFontsToManager(AssetManager& mAssetManager)
			{
				for(const auto& f : getFilteredFiles({".ttf", ".otf", ".pfm"}))
				{
					std::string id{ssvu::getReplaced(f, rootPath, "")};
					mAssetManager.load<sf::Font>(id, f);
					ssvu::lo("ssvs::AssetFolder::loadFontsToManager(" + rootPath.getStr() + ")") << id + " font added\n";
				}
			}
			inline void loadImagesToManager(AssetManager& mAssetManager)
			{
				for(const auto& f : getFilteredFiles({".png", ".jpg", ".bmp", ".jpeg"}))
				{
					std::string id{ssvu::getReplaced(f, rootPath, "")};
					mAssetManager.load<sf::Image>(id, f);
					ssvu::lo("ssvs::AssetFolder::loadImagesToManager(" + rootPath.getStr() + ")") << id + " image added\n";
				}
			}
			inline void loadTexturesToManager(AssetManager& mAssetManager)
			{
				for(const auto& f : getFilteredFiles({".png", ".jpg", ".bmp", ".jpeg"}))
				{
					std::string id{ssvu::getReplaced(f, rootPath, "")};
					mAssetManager.load<sf::Texture>(id, f);
					ssvu::lo("ssvs::AssetFolder::loadTexturesToManager(" + rootPath.getStr() + ")") << id + " texture added\n";
				}
			}
			inline void loadSoundBuffersToManager(AssetManager& mAssetManager)
			{
				for(const auto& f : getFilteredFiles({".wav", ".ogg"}))
				{
					std::string id{ssvu::getReplaced(f, rootPath, "")};
					mAssetManager.load<sf::SoundBuffer>(id, f);
					ssvu::lo("ssvs::AssetFolder::loadSoundsToManager(" + rootPath.getStr() + ")") << id + " soundBuffer added\n";
				}
			}
			inline void loadMusicsToManager(AssetManager& mAssetManager)
			{
				for(const auto& f : getFilteredFiles({".wav", ".ogg"}))
				{
					std::string id{ssvu::getReplaced(f, rootPath, "")};
					mAssetManager.load<sf::Music>(id, f);
					ssvu::lo("ssvs::AssetFolder::loadMusicsToManager(" + rootPath.getStr() + ")") << id + " music added\n";
				}
			}
			inline void loadShadersToManager(AssetManager& mAssetManager)
			{
				for(const auto& f : getFilteredFiles({".vert"}))
				{
					std::string id{ssvu::getReplaced(f, rootPath, "")};
					mAssetManager.load<sf::Shader>(id, f, sf::Shader::Type::Vertex, Impl::ShaderFromPath{});
					ssvu::lo("ssvs::AssetFolder::loadShadersToManager(" + rootPath.getStr() + ")") << id + " vertex shader added\n";
				}
				for(const auto& f : getFilteredFiles({".frag"}))
				{
					std::string id{ssvu::getReplaced(f, rootPath, "")};
					mAssetManager.load<sf::Shader>(id, f, sf::Shader::Type::Fragment, Impl::ShaderFromPath{});
					ssvu::lo("ssvs::AssetFolder::loadShadersToManager(" + rootPath.getStr() + ")") << id + " fragment shader added\n";
				}
			}

		public:
			inline AssetFolder(const Path& mRootPath) : rootPath{mRootPath}, files{ssvufs::getScan<ssvufs::Mode::Recurse, ssvufs::Type::File>(rootPath)} { }
			inline void loadToManager(AssetManager& mAssetManager)
			{
				loadImagesToManager(mAssetManager);
				loadTexturesToManager(mAssetManager);
				loadSoundBuffersToManager(mAssetManager);
				loadMusicsToManager(mAssetManager);
				loadFontsToManager(mAssetManager);
				loadShadersToManager(mAssetManager);

				ssvu::lo().flush();
			}
	};
}

#endif
