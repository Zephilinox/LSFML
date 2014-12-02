#include "LSFML.hpp"

#ifdef OS_WINDOWS
    #define EXPORTDLL __declspec(dllexport)
#else
    #define EXPORTDLL
#endif //_MSC_VER

///Lua: require("LSFML")
extern "C" EXPORTDLL int luaopen_LSFML(lua_State* L)
{
    registerlsf(L);
    return 1;
}

///Lua: package.loadlib("LSFML.dll", "system")
extern "C" EXPORTDLL int system(lua_State* L)
{
    registerlsfSystem(L);
    return 1;
}

///Lua: package.loadlib("LSFML.dll", "window")
extern "C" EXPORTDLL int window(lua_State* L)
{
    registerlsfWindow(L);
    return 1;
}

///Lua: package.loadlib("LSFML.dll", "graphics")
extern "C" EXPORTDLL int graphics(lua_State* L)
{
    registerlsfGraphics(L);
    return 1;
}
