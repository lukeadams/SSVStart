// Copyright (c) 2013-2015 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVS_GAMESYSTEM_GAMESTATE
#define SSVS_GAMESYSTEM_GAMESTATE

namespace ssvs
{
    class GameEngine;

    class GameState
    {
        friend GameEngine;

    private:
        using ITrigger = Input::Trigger;
        using IType = Input::Type;
        using IMode = Input::Mode;
        using IFunc = InputFunc;
        using EventDelegate = ssvu::Delegate<void(const sf::Event&)>;

        Input::Manager inputManager;
        std::map<sf::Event::EventType, EventDelegate> eventDelegates;

        inline void handleEvent(const sf::Event& mEvent)
        {
            onAnyEvent(mEvent);
            eventDelegates[mEvent.type](mEvent);
        }
        inline void update(FT mFT) { onUpdate(mFT); }
        inline void draw() { onDraw(); }

        inline void updateInput(Input::InputState& mInputState, FT mFT)
        {
            inputManager.update(mInputState, mFT);
        }
        inline void refreshInput(Input::InputState& mInputState)
        {
            inputManager.refresh(mInputState);
        }

    public:
        ssvu::Delegate<void()> onDraw, onPostUpdate;
        ssvu::Delegate<void(FT)> onUpdate;
        EventDelegate onAnyEvent;

        inline GameState() = default;

        inline GameState(const GameState&) = delete;
        inline GameState& operator=(const GameState&) = delete;

        inline auto& addInput(ITrigger mTrigger, IFunc mFuncOn, IFunc mFuncOff,
            IType mType = IType::Always, IMode mMode = IMode::Overlap)
        {
            return inputManager.emplace(
                mTrigger, mType, mMode, mFuncOn, mFuncOff);
        }
        inline auto& addInput(ITrigger mTrigger, IFunc mFuncOn,
            IType mType = IType::Always, IMode mMode = IMode::Overlap)
        {
            return addInput(
                mTrigger, mFuncOn, Impl::getNullInputFunc(), mType, mMode);
        }

        inline auto& onEvent(sf::Event::EventType mEventType)
        {
            return eventDelegates[mEventType];
        }
        inline void ignoreNextInputs() noexcept
        {
            inputManager.ignoreNextInputs();
        }
    };
}

#endif
