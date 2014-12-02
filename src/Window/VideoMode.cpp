#include "Window/VideoMode.hpp"

namespace lsf
{

VideoMode::VideoMode(float x, float y, float bit)
    : m_videoMode(x, y, bit)
{
}

VideoMode::VideoMode(const sf::VideoMode& videoMode)
    : m_videoMode(videoMode)
{
}

bool VideoMode::isValid()
{
    return m_videoMode.isValid();
}

VideoMode VideoMode::getDesktopMode()
{
    return VideoMode(sf::VideoMode::getDesktopMode());
}

//const luabridge::LuaRef& VideoMode::getFullscreenModes() {}

} //lsf

void registerVideoMode(lua_State* L)
{
    luabridge::getGlobalNamespace(L)
        .beginNamespace("sfml")
            .beginClass<lsf::VideoMode>("VideoMode")
                .addConstructor<void(*)(float, float, float)>()
                .addFunction("isValid", &lsf::VideoMode::isValid)
                .addStaticFunction("getDesktopMode", &lsf::VideoMode::getDesktopMode)
            .endClass()
        .endNamespace()
    ;
}
