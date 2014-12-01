#include "System/System.hpp"

#include "System/Time.hpp"
#include "System/Clock.hpp"

void registerSystem(lua_State* L)
{
    registerTime(L);
    registerClock(L);
}
