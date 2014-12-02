#include "Window.hpp"

#include "Graphics/RenderWindow.hpp"
#include "Graphics/Color.hpp"

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
    registerColor(L);
}
