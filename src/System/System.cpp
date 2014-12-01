#include "System/System.hpp"

#include "System/Clock.hpp"

void registerSystem(lua_State* L)
{
    registerClock(L);
}
