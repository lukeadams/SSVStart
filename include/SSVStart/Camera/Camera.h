// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVS_CAMERA
#define SSVS_CAMERA

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "SSVStart/Global/Typedefs.h"

namespace ssvs
{
	class GameWindow;

	class Camera
	{
		private:
			GameWindow& gameWindow;
			sf::RenderWindow& renderWindow;
			sf::View view;
			Vec2f skew{1, 1}, offset{0, 0};

		public:
			Camera(GameWindow& mGameWindow, sf::View mView);

			void apply();
			inline void unapply() { renderWindow.setView(renderWindow.getDefaultView()); }

			inline void resize(Vec2f mOffset, Vec2f mSize)
			{
				const auto& size(renderWindow.getSize());
				view = sf::View{{0, 0, mSize.x, mSize.y}};
				view.setViewport({mOffset.x / size.x, mOffset.y / size.y, mSize.x / size.x, mSize.y / size.y});
			}

			inline void move(Vec2f mVec) 				{ view.move(mVec); }
			inline void zoom(float mFactor) 			{ view.zoom(mFactor); }
			inline void centerOn(Vec2f mPosition) 		{ view.setCenter(mPosition); }
			inline void rotate(float mAngle)			{ view.rotate(mAngle); }

			inline void setView(const sf::View& mView)	{ view = mView; }
			inline void setRotation(float mAngle)		{ view.setRotation(mAngle); }
			inline void setSkew(Vec2f mSkew)			{ skew = mSkew; }
			inline void setOffset(Vec2f mOffset)		{ offset = mOffset; }

			inline sf::View getView() const							{ return view; }
			inline float getRotation() const						{ return view.getRotation(); }
			inline Vec2f getSkew() const							{ return skew; }
			inline Vec2f getOffset() const							{ return offset; }
			inline Vec2f getCenter() const							{ return view.getCenter(); }
			inline Vec2f getMousePosition() const					{ return renderWindow.mapPixelToCoords({sf::Mouse::getPosition(renderWindow)}, view); }
			inline Vec2f getConvertedCoords(Vec2i mPosition) const	{ return renderWindow.mapPixelToCoords(mPosition, view); }
			inline bool isInView(Vec2f mPosition) const
			{
				return mPosition.x <= view.getCenter().x + view.getSize().x && (mPosition.x >= view.getCenter().x - view.getSize().x &&
					(mPosition.y <= view.getCenter().y + view.getSize().y && mPosition.y >= view.getCenter().y - view.getSize().y));
			}
	};
}

#endif
