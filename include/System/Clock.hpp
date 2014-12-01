#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <Lua5.2/lua.hpp>
#include <LuaBridge/luabridge.h>
#include <SFML/System/Clock.hpp>

#include "System/Time.hpp"

namespace lsf
{

//We need to wrap sf::Clock because we need to return lsf::Time
class Clock
{
public:
    Clock() = default;

    Time restart();

    sf::Clock m_clock;
};

} //lsf

void registerClock(lua_State* L);

#endif
