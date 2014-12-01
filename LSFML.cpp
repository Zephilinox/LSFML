#include "libLSFML.hpp"

extern "C" __declspec(dllexport) int luaopen_LSFML(lua_State* L)
{
    registerLSFML(L);
    return 1;
}
