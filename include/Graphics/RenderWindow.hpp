#ifndef RENDERWINDOW_HPP
#define RENDERWINDOW_HPP

#include <Lua5.2/lua.hpp>
#include <LuaBridge/luabridge.h>
#include <SFML/Graphics/RenderWindow.hpp>

namespace lsf
{

class RenderWindow
{
public:
    RenderWindow() = default;
    RenderWindow(float, float, float, const std::string&);

    sf::RenderWindow m_window;
};

} //lsf

void registerRenderWindow(lua_State* L);

#endif
