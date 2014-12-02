#include <iostream>

#include "LSFML.hpp"

#include "System.hpp"
//#include "Window.hpp"
//#include "Graphics.hpp

void registerlsf(lua_State* L)
{
    registerlsfSystem(L);
    registerlsfWindow(L);
    registerlsfGraphics(L);
}

void registerlsfSystem(lua_State* L)
{
    registerSystem(L);
}

void registerlsfWindow(lua_State* L)
{
    //registerWindow(L)
}

void registerlsfGraphics(lua_State* L)
{
    //registerWindow(L)
}
