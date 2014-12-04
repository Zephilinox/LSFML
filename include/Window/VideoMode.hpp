#ifndef VIDEOMODE_HPP
#define VIDEOMODE_HPP

#include <Lua5.2/lua.hpp>
#include <LuaBridge/luabridge.h>
#include <SFML/Window/VideoMode.hpp>

namespace lsf
{

class VideoMode
{
public:
    VideoMode() = default;
    VideoMode(float, float, float);
    VideoMode(const sf::VideoMode&);

    VideoMode getCopy();

    float getWidth() const;
    float getHeight() const;
    float getBpp() const;

    void setWidth(float);
    void setHeight(float);
    void setBpp(float);

    bool isValid();

    static VideoMode getDesktopMode();
    //static const luabridge::LuaRef& getFullscreenModes();

    sf::VideoMode m_videoMode;
};

} //lsf

void registerVideoMode(lua_State* L);

#endif // VIDEOMODE_HPP
