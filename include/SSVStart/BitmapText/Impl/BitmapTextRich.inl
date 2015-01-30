// Copyright (c) 2013-2014 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVS_BITMAPTEXT_IMPL_BITMAPTEXTRICH_INL
#define SSVS_BITMAPTEXT_IMPL_BITMAPTEXTRICH_INL

#include <SSVUtils/MemoryManager/MemoryManager.hpp>
#include "SSVStart/Global/Typedefs.hpp"
#include "SSVStart/BitmapText/Impl/BitmapFont.hpp"
#include "SSVStart/BitmapText/Impl/BitmapTextData.hpp"
#include "SSVStart/BitmapText/Impl/BitmapTextBase.hpp"
#include "SSVStart/BitmapText/Impl/BitmapText.hpp"
#include "SSVStart/BitmapText/Impl/Parts.hpp"
#include "SSVStart/BitmapText/Impl/BitmapTextRich.hpp"
#include "SSVStart/BitmapText/Impl/Parts.inl"

namespace ssvs
{
	template<typename T, typename... TArgs> auto& BitmapTextRich::mk(TArgs&&... mArgs)				{ return basePart->mk<T>(ssvu::fwd<TArgs>(mArgs)...); }
	template<typename T, typename... TArgs> auto& BitmapTextRich::mk(T*& mTarget, TArgs&&... mArgs)	{ return basePart->mk<T>(mTarget, ssvu::fwd<TArgs>(mArgs)...); }

	template<typename T> inline auto& BitmapTextRich::operator<<(T&& mX) { return ((*basePart) << ssvu::fwd<T>(mX)); }
}

#endif