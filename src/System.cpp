#include "System.hpp"

#include "System/Time.hpp"
#include "System/Clock.hpp"
#include "System/Vector2.hpp"

namespace lsf
{
    void sleep(Time time)
    {
        sf::sleep(time.m_time);
    }

} //lsf

void registerSystem(lua_State* L)
{
    luabridge::getGlobalNamespace(L)
        .beginNamespace("sfml")
            .addFunction("sleep", &lsf::sleep)
        .endNamespace()
    ;

    registerTime(L);
    registerClock(L);
    registerVector2(L);
}
