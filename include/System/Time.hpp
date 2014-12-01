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
    long int asMilliseconds();
    long int asMicroseconds();

    sf::Time m_time;
};

Time seconds(float);
Time milliseconds(long int);
Time microseconds(long int);

} //lsf

void registerTime(lua_State* L);

#endif
