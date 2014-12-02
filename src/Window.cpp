#include "Window.hpp"

namespace lsf
{

} //lsf

void registerWindow(lua_State* L)
{
    luabridge::getGlobalNamespace(L)
        .beginNamespace("sfml")
        .endNamespace()
    ;
}
