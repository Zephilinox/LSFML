#include "System/Clock.hpp"

#include <iostream>

namespace lsf
{

void clockPrint(const std::string& msg)
{
    std::cout << "[CLOCK]" << msg;
}

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
            .addFunction("clockPrint", &lsf::clockPrint)
        .endNamespace()
    ;
}
