// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#include "TimelineManager.h"
#include "Utils/Utils.h"

using namespace ssvs::Utils;

namespace ssvs
{
	Timeline& TimelineManager::create() { return memoryManager.create(); }
	void TimelineManager::update(float mFrameTime)
	{
		for(auto& t : memoryManager.getItems()) { t->update(mFrameTime); if(t->isFinished()) memoryManager.del(t); }
		memoryManager.cleanUp();
	}
	void TimelineManager::clear() { memoryManager.clear(); }
}
