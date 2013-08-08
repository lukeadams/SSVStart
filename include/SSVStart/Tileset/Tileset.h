// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVS_TILESET
#define SSVS_TILESET

#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "SSVStart/Global/Typedefs.h"

namespace ssvs
{
	class Tileset
	{
		private:
			Vec2u tileSize;
			std::unordered_map<std::string, Vec2u> labels;

		public:
			Tileset() = default;
			Tileset(Vec2u mTileSize) : tileSize{mTileSize} { }

			inline void setTileSize(Vec2u mTileSize)								{ tileSize = mTileSize; }
			inline void setLabel(const std::string& mLabel, Vec2u mIndex)			{ labels[mLabel] = mIndex; }

			inline Vec2u getIndex(const std::string& mLabel) const					{ return labels.at(mLabel); }
			inline sf::IntRect operator[](Vec2u mIndex) const						{ return sf::IntRect(mIndex.x * tileSize.x, mIndex.y * tileSize.y, tileSize.x, tileSize.y); }
			inline const std::unordered_map<std::string, Vec2u>& getLabels() const	{ return labels; }
			inline Vec2u getTileSize() const										{ return tileSize; }
	};
}

#endif
