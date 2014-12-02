#ifndef RENDERWINDOW_HPP
#define RENDERWINDOW_HPP

#include <Lua5.2/lua.hpp>
#include <LuaBridge/luabridge.h>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Graphics/Color.hpp"
#include "Window/VideoMode.hpp"

namespace lsf
{

class RenderWindow
{
public:
    RenderWindow() = default;
    RenderWindow(VideoMode, const std::string&);

    void clear(const Color&);
    //void draw();
    void display();

    sf::RenderWindow m_window;
};

} //lsf

void registerRenderWindow(lua_State* L);

#endif
