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

int Time::asMilliseconds()
{
    return m_time.asMilliseconds();
}

int Time::asMicroseconds()
{
    return m_time.asMicroseconds();
}

///Standalone

Time seconds(float sec)
{
    return Time(sf::seconds(sec));
}

Time milliseconds(int milSec)
{
    return Time(sf::milliseconds(milSec));
}

Time microseconds(int micSec)
{
    return Time(sf::microseconds(micSec));
}

} //lsf

void registerTime(lua_State* L)
{
    luabridge::getGlobalNamespace(L)
        .beginNamespace("sfml")
            .addFunction("seconds", &lsf::seconds)
            .addFunction("milliseconds", &lsf::seconds)
            .addFunction("microseconds", &lsf::seconds)
            .beginClass<lsf::Time>("Time")
                .addConstructor<void(*)(void)>()
                .addFunction("asSeconds", &lsf::Time::asSeconds)
                .addFunction("asMilliseconds", &lsf::Time::asMilliseconds)
                .addFunction("asMicroseconds", &lsf::Time::asMicroseconds)
            .endClass()
        .endNamespace()
    ;
}
