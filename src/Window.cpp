#include "Window.hpp"

#include "Window/VideoMode.hpp"

namespace lsf
{

} //lsf

void registerWindow(lua_State* L)
{
    luabridge::getGlobalNamespace(L)
        .beginNamespace("sfml")
        .endNamespace()
    ;

    registerVideoMode(L);
}
