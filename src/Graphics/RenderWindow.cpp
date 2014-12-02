#include "Graphics/RenderWindow.hpp"

#include <iostream>

namespace lsf
{
    RenderWindow::RenderWindow(float x, float y, float bit, const std::string& title)
        : m_window(sf::VideoMode(x, y, bit), title)
    {
    }

} //lsf

void registerRenderWindow(lua_State* L)
{
    luabridge::getGlobalNamespace(L)
        .beginNamespace("sfml")
            .beginClass<lsf::RenderWindow>("RenderWindow")
                .addConstructor<void(*)(float, float, float, std::string)>()
            .endClass()
        .endNamespace()
    ;
}
