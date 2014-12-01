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
    Time(const Time& t);
    Time(const sf::Time&);

    Time add(const Time&);
    Time sub(const Time&);
    bool eq(const Time&);
    bool lt(const Time&);
    bool le(const Time&);

    float asSeconds() const;
    long int asMilliseconds() const;
    long int asMicroseconds() const;

    sf::Time m_time;
};

Time seconds(float);
Time milliseconds(long int);
Time microseconds(long int);

} //lsf

void registerTime(lua_State* L);

#endif
