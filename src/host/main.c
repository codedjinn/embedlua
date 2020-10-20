
#include "lib/lua/include/lua.h"
#include "lib/lua/include/lualib.h"
#include "lib/lua/include/lauxlib.h"

#include <stdio.h>

int main() 
{
    printf("Initializing Lua\n\n");

    lua_State* lua = luaL_newstate();

    luaL_openlibs(lua);

    luaL_dofile(lua , "first.lua");

    //luaL_dostring(lua, "print 'from LUA'");

    printf("\nShutting down Lua...");

    lua_close(lua);

    printf("\nDone");

    return 0;
}