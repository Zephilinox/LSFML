#include <iostream>

#include "libLSFML.hpp"

#include "System/System.hpp"

namespace lsfml
{
    void print(const std::string& msg)
    {
        std::cout << msg;
    }
}

void registerLSFML(lua_State* L)
{
    luabridge::getGlobalNamespace(L)
        .beginNamespace("sfml")
            .addFunction("print", &lsfml::print)
        .endNamespace()
    ;

    registerSystem(L);
}
