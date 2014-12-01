#include "System/Clock.hpp"

#include <iostream>

namespace lsf
{

Time Clock::restart()
{
    return m_clock.restart();
}

} //lsf

void registerClock(lua_State* L)
{
    luabridge::getGlobalNamespace(L)
        .beginNamespace("sfml")
            .beginClass<lsf::Clock>("Clock")
                .addConstructor<void(*)(void)>()
                .addFunction("restart", &lsf::Clock::restart)
            .endClass()
        .endNamespace()
    ;
}
