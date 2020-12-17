#include "lib/lua/include/lua.hpp"

#include <stdlib.h>
#include <stdio.h>

#include "src/script_manager.h"

int main()
{
    ScriptManager mgr;
    mgr.Initialize();
    mgr.Load("entity1.lua");
    mgr.ExecuteTableMethod("ent", "update");


    MethodInputBuilder builder;
    builder.AddNumber(10.0);
    builder.AddString("pew pew pew");

    mgr.ExecuteTableMethod("ent", "foo", builder);
    // lua_State * L = luaL_newstate();
    // luaL_openlibs(L);

    // luaL_loadfile(L, "entity1.lua");

    // // execute script
    // //auto lua_script = script.c_str();
    // //luaL_loadstring(L, str);
    // //int load_stat = luaL_loadbuffer(L,lua_script,strlen(lua_script),lua_script);
    // lua_pcall(L, 0, 0, 0);

    // // load the function from global
    // int result = lua_getglobal(L, "ent");
    // if (!lua_isnil(L, 0))
    // {
    //     lua_getfield(L, -1, "update");
    //     if (lua_isfunction(L, -1))
    //     {
    //         lua_pcall(L, 0, 1, 0);
    //         if (!lua_isnil(L, -1))
    //         {
    //             int val = lua_tonumber(L, -1);
    //             printf("%d", val);
    //         }
    //     }
    // }    

    // // cleanup
    // lua_close(L);
    
    // lua_State* lua = luaL_newstate();
    // luaL_openlibs(lua);

    // //int result = luaL_loadfile(lua, "entity1.lua");
    // if (luaL_loadfile(lua, "entity1.lua"))
    // {
    //     printf("Error loading script\n");
    //     printf(lua_tostring(lua, -1));
    //     printf("\n");
    //     lua_pop(lua, 1);
    // }
    // else
    // {
    //     printf("Script loaded!");
    // }


    // lua_getglobal(lua, "update");
    // if (lua_isfunction(lua, -1))
    // {
    //     lua_pcall(lua, 0, 0, 0);
    //     int result = lua_tonumber(lua, -1);

    //     printf("%d", result);

    //     lua_pop(lua, 1);
    // }
    // else if (lua_isnil(lua, -1))
    // {
    //     printf("ITS FUCKING NIL!\n");
    // }

    // lua_close(lua);

    return 0;
}