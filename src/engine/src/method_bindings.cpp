
#include "method_bindings.h"

#include <cassert>

#include "logger.h"

//-------------------------------------------------
// Logging
//-------------------------------------------------
int luaLogInfo(lua_State* lua)
{
    assert(lua_isstring(lua, 1));
    std::string msg = std::string(lua_tostring(lua, 1));
    msg.insert(0, "<LUA> ");
    LogInfo(msg);
    return 0;
}
int luaLogDebug(lua_State* lua)
{
    assert(lua_isstring(lua, 1));
    std::string msg = std::string(lua_tostring(lua, 1));
    msg.insert(0, "<LUA> ");
    LogDebug(msg);
    return 0;
}
int luaLogError(lua_State* lua)
{
    assert(lua_isstring(lua, 1));
    std::string msg = std::string(lua_tostring(lua, 1));
    msg.insert(0, "<LUA> ");
    LogError(msg);
    return 0;
}

void BindLoggingMethods(lua_State* lua)
{
    lua_pushcclosure(lua, luaLogInfo, 1);
    lua_setglobal(lua, "LogInfo");

    lua_pushcclosure(lua, luaLogDebug, 1);
    lua_setglobal(lua, "LogDebug");

    lua_pushcclosure(lua, luaLogError, 1);
    lua_setglobal(lua, "LogError");
}

//-------------------------------------------------
// Game
//-------------------------------------------------
void BindGameMethods(lua_State* lua)
{

}

//-------------------------------------------------
// Entities
//-------------------------------------------------
int luaSpawnEntity(lua_State* lua)
{
    assert(lua_isstring(lua, 1));
    std::string name = lua_tostring(lua, 1);
    lua_pushnumber(lua, 1);
    return 1;
}

void BindEntityMethods(lua_State* lua, const EntityManager& mgr)
{
    lua_pushcclosure(lua, luaSpawnEntity, 1);
    lua_setglobal(lua, "Engine_Spawn_Entity");
}

