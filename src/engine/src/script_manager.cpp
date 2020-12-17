
#include "script_manager.h"

void ScriptManager::Initialize()
{
    _lua = luaL_newstate();
    luaL_openlibs(_lua);    
}

void ScriptManager::Load(std::string filename)
{
    int result = luaL_loadfile(_lua, filename.c_str());
    if (result || lua_pcall(_lua, 0, 0, 0))
    {
        LogError("Failed to load script file. " + filename);
    }
}

void ScriptManager::ExecuteTableMethod(std::string tableName, std::string methodName)
{
    lua_getglobal(_lua, tableName.c_str());
    if (!lua_isnil(_lua, 0))
    {
        lua_getfield(_lua, -1, methodName.c_str());
        if (lua_isfunction(_lua, -1))
        {
            lua_pcall(_lua, 0, 0, 0);
        }
    }
    else
    {
        LogDebug("Unknown error! " + tableName + "::" + methodName);
    }
}

void ScriptManager::ExecuteTableMethod(std::string tableName, std::string methodName, MethodInputBuilder builder)
{
    lua_getglobal(_lua, tableName.c_str());
    if (!lua_isnil(_lua, 0))
    {
        lua_getfield(_lua, -1, methodName.c_str());
        if (lua_isfunction(_lua, -1))
        {
            // set inputs
            for (auto& input: builder.getInputs())
            {
                if (input.type == DataType::nil)
                {
                    lua_pushnil(_lua);
                }
                else if (input.type == DataType::boolean)
                {
                    lua_pushboolean(_lua, input.bValue);
                }
                else if (input.type == DataType::number)
                {
                    lua_pushnumber(_lua, input.numValue);
                }
                else if (input.type == DataType::string)
                {
                    lua_pushstring(_lua, input.sValue.c_str());
                }
            }
            lua_pcall(_lua, builder.getCount(), 0, 0);
        }
        else
        {
            LogDebug("methodName does not exist, " + tableName + "::" + methodName);
        }
        
    }
    else
    {
        LogDebug("Unknown error." + tableName + "::" + methodName);
    }
}

ScriptManager::~ScriptManager()
{
    if (_lua)
    {
        lua_close(_lua);
    }
}