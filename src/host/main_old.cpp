
#include "lib/lua/include/lua.hpp"

#include "framework/entity.h"

#include <stdio.h>
#include <iostream>

using namespace std;

#include "utils.h"

#include "framework/game.h"

#include "lib/json/includes/json.h"

int mult(lua_State* lua)
{
    int a = luaL_checkinteger(lua, 1);
    int b = luaL_checkinteger(lua, 2);

    lua_Integer c = a * b;

    lua_pushinteger(lua, c);

    return 1;
}

lua_State* init_lua()
{
    printf("Initializing Lua\n\n");

    lua_State* lua = luaL_newstate();
    
    // load standard libs for lua
    luaL_openlibs(lua);

    printf("\nDone\n");

    return lua;
}

void run_script(lua_State* lua, const char* str)
{
    int err_result = luaL_dofile(lua, "first.lua");
    if (err_result == 0)
    {
        printf("script succeeded\n");
    }
    else
    {
        printf("script failed\n");
    }
}

void close_lua(lua_State* lua)
{
    printf("\nShutting down Lua...");
    lua_close(lua);
}

void spawn_entity(const char* name)
{    
}

int main() 
{
  //  auto lua = init_lua();
    try
    {
        // auto str_json = read_file("entity1.json");
        // int json_len = strlen(str_json);

        std::ifstream file;
        file.open("entity1.json");

        Json::Value root;

        JSONCPP_STRING err;

        Json::CharReaderBuilder builder;
        const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
        if (!Json::parseFromStream(builder, file, &root, &err))
        {
            printf("error\n");
        }
        // if (!reader->parse(str_json, str_json + json_len, &root, &err))
        // {
        //     printf("error\n");
        //     return -1;
        // }

        
        printf("'name' %s", root.get("name", "bla").asCString());

        //cout << root << endl;
    }
    catch(const std::exception& e)
    {
        printf("Exception: %s", e.what());
    }
    // run_script(lua, "first.lua");

    // lua_getglobal(lua, "init");
    // if (lua_isfunction(lua, -1))
    // {
    //     printf("found [init]\n");
    //     lua_pcall(lua, 0, 1, 0);

    //     int c = lua_toboolean(lua, -1);
    //     printf("ret num %d", (bool)c);
    // }

    // lua_getglobal(lua, "update");
    // if (lua_isfunction(lua, -1))
    // {
    //     printf("\nfound [update]\n");
    //     lua_pushnumber(lua, 10);
    //     //lua_pop(lua, 1);

    //     constexpr int num_args = 1;
    //     constexpr int num_returns = 0;

    //     lua_pcall(lua, num_args, num_returns, 0);
    //  //   lua_pop(lua, 1);
    // }

    // //Entity* ent = new Entity();
    // //printf("do something %s\n", ent->get_script());

    // close_lua(lua);

    return 0;
}

