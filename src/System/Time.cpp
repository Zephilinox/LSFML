#include "System/Time.hpp"

namespace lsf
{

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

} //lsf

void registerTime(lua_State* L)
{
    luabridge::getGlobalNamespace(L)
        .beginNamespace("sfml")
            .beginClass<lsf::Time>("Time")
                .addConstructor<void(*)(void)>()
                .addFunction("asSeconds", &lsf::Time::asSeconds)
                .addFunction("asMilliseconds", &lsf::Time::asMilliseconds)
                .addFunction("asMicroseconds", &lsf::Time::asMicroseconds)
            .endClass()
        .endNamespace()
    ;
}
