#include "System/Clock.hpp"

#include <iostream>

namespace lsf
{

Time Clock::restart()
{
    return m_clock.restart();
}

Time Clock::getElapsedTime()
{
    return m_clock.getElapsedTime();
}

} //lsf

void registerClock(lua_State* L)
{
    luabridge::getGlobalNamespace(L)
        .beginNamespace("sfml")
            .beginClass<lsf::Clock>("Clock")
                .addConstructor<void(*)(void)>()
                .addFunction("getElapsedTime", &lsf::Clock::getElapsedTime)
                .addFunction("restart", &lsf::Clock::restart)
            .endClass()
        .endNamespace()
    ;
}
