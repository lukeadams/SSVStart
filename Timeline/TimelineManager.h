// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVS_TIMELINE_MANAGER
#define SSVS_TIMELINE_MANAGER

#include "Timeline.h"
#include "Utils/MemoryManager.h"

namespace ssvs
{
	class TimelineManager
	{
		private:
			Utils::MemoryManager<Timeline> memoryManager;

		public:
			TimelineManager() = default;

			Timeline& create();
			void update(float mFrameTime);
			void clear();
	};
}

#endif 
