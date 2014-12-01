#ifndef TIME_HPP
#define TIME_HPP

#include <Lua5.2/lua.hpp>
#include <LuaBridge/luabridge.h>
#include <SFML/System/Time.hpp>

namespace lsf
{

class Time
{
public:
    Time() = default;
    Time(sf::Time);

    float asSeconds();
    int asMilliseconds();
    int asMicroseconds();

    sf::Time m_time;
};

} //lsf

void registerTime(lua_State* L);

#endif
