#include "Window.hpp"

#include "Graphics/RenderWindow.hpp"

namespace lsf
{

} //lsf

void registerGraphics(lua_State* L)
{
    luabridge::getGlobalNamespace(L)
        .beginNamespace("sfml")
        .endNamespace()
    ;

    registerRenderWindow(L);
}
