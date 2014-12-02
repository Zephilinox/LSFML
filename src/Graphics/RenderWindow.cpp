#include "Graphics/RenderWindow.hpp"

#include <iostream>

#include "Window/VideoMode.hpp"

namespace lsf
{
    RenderWindow::RenderWindow(VideoMode vm, const std::string& title)
        : m_window(vm.m_videoMode, title)
    {
    }

    void RenderWindow::clear(const Color& c)
    {
        m_window.clear(c.m_color);
    }

    //void draw();
    void RenderWindow::display()
    {
        m_window.display();
    }

} //lsf

void registerRenderWindow(lua_State* L)
{
    luabridge::getGlobalNamespace(L)
        .beginNamespace("sfml")
            .beginClass<lsf::RenderWindow>("RenderWindow")
                .addConstructor<void(*)(lsf::VideoMode, std::string)>()
                .addFunction("clear", &lsf::RenderWindow::clear)
                .addFunction("display", &lsf::RenderWindow::display)
            .endClass()
        .endNamespace()
    ;
}
