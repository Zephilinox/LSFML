#include <iostream>

#include "libLSFML.hpp"

#include "System/System.hpp"

void registerlsf(lua_State* L)
{
    registerSystem(L);
}
