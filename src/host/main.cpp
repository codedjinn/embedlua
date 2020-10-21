
#include "lib/lua/include/lua.hpp"

#include "entity.h"

#include <stdio.h>

int mult(lua_State* lua)
{
    int a = luaL_checkinteger(lua, 1);
    int b = luaL_checkinteger(lua, 2);

    lua_Integer c = a * b;

    lua_pushinteger(lua, c);

    return 1;
}

int main() 
{
    printf("Initializing Lua\n\n");

    lua_State* lua = luaL_newstate();
    
    // load standard libs for lua
    luaL_openlibs(lua);

    lua_pushinteger(lua, 42);
    lua_setglobal(lua, "gnumber");

    lua_pushcfunction(lua, mult);

    lua_setglobal(lua, "mult");

    int err_result = luaL_dofile(lua, "first.lua");
    if (err_result == 0)
    {
        printf("OK\n");
    }
    else
    {
        printf("Failed\n");
    }    

    printf("\nShutting down Lua...");

    lua_close(lua);

    printf("\nDone");

    return 0;
}