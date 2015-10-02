// Copyright (c) 2013-2015 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVS_GAMESYSTEM_TIMERS_BASE_INL
#define SSVS_GAMESYSTEM_TIMERS_BASE_INL

namespace ssvs
{
inline void TimerBase::runDraw() { gameEngine.drawFromTimer(); }
}

#endif
