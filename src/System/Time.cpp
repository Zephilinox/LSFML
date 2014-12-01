#include "System/Time.hpp"

#include <iostream>

namespace lsf
{

///Time
Time::Time(const Time& time)
{
    m_time = time.m_time;
}

Time::Time(const sf::Time& time)
{
    m_time = time;
}

Time Time::add(const Time& other)
{
    return Time(m_time + other.m_time);
}

Time Time::sub(const Time& other)
{
     return m_time - other.m_time;
}

bool Time::eq(const Time& other)
{
    return m_time == other.m_time;
}

bool Time::lt(const Time& other)
{
    return m_time < other.m_time;
}

bool Time::le(const Time& other)
{
    return m_time <= other.m_time;
}

float Time::asSeconds() const
{
    return m_time.asSeconds();
}

long int Time::asMilliseconds() const
{
    return m_time.asMilliseconds();
}

long int Time::asMicroseconds() const
{
    return m_time.asMicroseconds();
}

///Standalone

Time seconds(float sec)
{
    return Time(sf::seconds(sec));
}

Time milliseconds(long int milSec)
{
    return Time(sf::milliseconds(milSec));
}

Time microseconds(long int micSec)
{
    return Time(sf::microseconds(micSec));
}

} //lsf

void registerTime(lua_State* L)
{
    luabridge::getGlobalNamespace(L)
        .beginNamespace("sfml")
            .addFunction("seconds", &lsf::seconds)
            .addFunction("milliseconds", &lsf::milliseconds)
            .addFunction("microseconds", &lsf::microseconds)
            .beginClass<lsf::Time>("Time")
                .addConstructor<void(*)(void)>()
                .addFunction("__add", &lsf::Time::add)
                .addFunction("__sub", &lsf::Time::sub)
                .addFunction("__eq", &lsf::Time::eq)
                .addFunction("__le", &lsf::Time::le)
                .addFunction("__lt", &lsf::Time::lt)
                .addFunction("asSeconds", &lsf::Time::asSeconds)
                .addFunction("asMilliseconds", &lsf::Time::asMilliseconds)
                .addFunction("asMicroseconds", &lsf::Time::asMicroseconds)
            .endClass()
        .endNamespace()
    ;
}
