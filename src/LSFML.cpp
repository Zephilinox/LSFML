#include <iostream>

#include "LSFML.hpp"

#include "System.hpp"

void registerlsf(lua_State* L)
{
    registerSystem(L);
}
