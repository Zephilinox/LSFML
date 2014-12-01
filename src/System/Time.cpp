#include "System/Time.hpp"

namespace lsf
{

///Time
Time::Time(sf::Time time)
{
    m_time = time;
}

float Time::asSeconds()
{
    return m_time.asSeconds();
}

long int Time::asMilliseconds()
{
    return m_time.asMilliseconds();
}

long int Time::asMicroseconds()
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
                .addFunction("asSeconds", &lsf::Time::asSeconds)
                .addFunction("asMilliseconds", &lsf::Time::asMilliseconds)
                .addFunction("asMicroseconds", &lsf::Time::asMicroseconds)
            .endClass()
        .endNamespace()
    ;
}
