#include <iostream>

#include "libLSFML.hpp"

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
}
