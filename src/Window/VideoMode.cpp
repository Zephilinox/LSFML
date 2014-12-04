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

VideoMode VideoMode::getCopy()
{
    return VideoMode(m_videoMode);
}

float VideoMode::getWidth() const
{
    return m_videoMode.width;
}

float VideoMode::getHeight() const
{
    return m_videoMode.height;
}

float VideoMode::getBpp() const
{
    return m_videoMode.bitsPerPixel;
}

void VideoMode::setWidth(float w)
{
    m_videoMode.width = w;
}

void VideoMode::setHeight(float h)
{
    m_videoMode.height = h;
}

void VideoMode::setBpp(float bpp)
{
    m_videoMode.bitsPerPixel = bpp;
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
                .addFunction("getCopy", &lsf::VideoMode::getCopy)
                .addProperty("width", &lsf::VideoMode::getWidth, &lsf::VideoMode::setWidth)
                .addProperty("height", &lsf::VideoMode::getHeight, &lsf::VideoMode::setHeight)
                .addProperty("bpp", &lsf::VideoMode::getBpp, &lsf::VideoMode::setBpp)
                .addFunction("isValid", &lsf::VideoMode::isValid)
                .addStaticFunction("getDesktopMode", &lsf::VideoMode::getDesktopMode)
            .endClass()
        .endNamespace()
    ;
}
