// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVS_INPUT_MANAGER
#define SSVS_INPUT_MANAGER

#include <vector>
#include <functional>
#include "SSVStart/Input/Bind.h"

namespace ssvs
{
	class GameWindow;

	namespace Input
	{
		using InputFunc = std::function<void(float)>;

		class Manager
		{
			private:
				std::vector<Bind> binds;

			public:
				inline void update(GameWindow& mGameWindow, float mFrameTime)	{ for(auto& b : binds) b.update(mFrameTime, mGameWindow); }
				inline void refresh(GameWindow& mGameWindow)					{ for(auto& b : binds) b.refresh(mGameWindow); }
				inline void add(const Bind& mBind)								{ binds.push_back(mBind); }
		};
	}
}

#endif
