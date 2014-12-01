#include "System/Clock.hpp"

#include <iostream>

namespace lsfml
{
    void clockPrint(const std::string& msg)
    {
        std::cout << "[CLOCK]" << msg;
    }
}

void registerClock(lua_State* L)
{
    luabridge::getGlobalNamespace(L)
        .beginNamespace("sfml")
            .addFunction("clockPrint", &lsfml::clockPrint)
        .endNamespace()
    ;
}
