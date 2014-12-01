#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <Lua5.2/lua.hpp>
#include <LuaBridge/luabridge.h>
#include <SFML/System.hpp>

void registerSystem(lua_State* L);

#endif
