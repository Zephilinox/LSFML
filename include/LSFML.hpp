#ifndef LSFML_HPP
#define LSFML_HPP

#include <Lua5.2/lua.hpp>
#include <LuaBridge/luabridge.h>

void registerlsf(lua_State* L);
void registerlsfSystem(lua_State* L);
void registerlsfWindow(lua_State* L);
void registerlsfGraphics(lua_State* L);

#endif
