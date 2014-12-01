#include "libLSFML.hpp"

extern "C" __declspec(dllexport) int luaopen_LSFML(lua_State* L)
{
    registerlsf(L);
    return 1;
}
