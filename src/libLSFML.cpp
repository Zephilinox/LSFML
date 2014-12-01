#include <iostream>

#include "libLSFML.hpp"

#include "System/System.hpp"

namespace lsf
{
    void print(const std::string& msg)
    {
        std::cout << msg;
    }
}

void registerlsf(lua_State* L)
{
    luabridge::getGlobalNamespace(L)
        .beginNamespace("sfml")
            .addFunction("print", &lsf::print)
        .endNamespace()
    ;

    registerSystem(L);
}
