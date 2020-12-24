
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
        std::string errMsg = "Failed to load script, " + filename + ", reason - " + lua_tostring(_lua, -1);
        LogError(errMsg);
        lua_pop(_lua, 1);
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
            if (lua_pcall(_lua, 0, 0, 0))
            {
                std::string errMsg = "Coudln't execute" + tableName + "::" + methodName + ", reason - " + lua_tostring(_lua, -1);
                LogError(errMsg);
            }
            lua_pop(_lua, 1);
        }
    }
    else
    {
        LogDebug("Unknown error! " + tableName + "::" + methodName);
    }
}

void ScriptManager::ExecuteTableMethod(std::string tableName, std::string methodName, LuaMethodInputs inputs)
{
    lua_getglobal(_lua, tableName.c_str());
    if (!lua_isnil(_lua, 0))
    {
        lua_getfield(_lua, -1, methodName.c_str());
        if (lua_isfunction(_lua, -1))
        {
            // set inputs
            for (auto& input: inputs.get())
            {
                switch (input.type)
                {
                    case DataType::nil:
                        lua_pushnil(_lua);
                        break;
                    case DataType::boolean:
                        lua_pushboolean(_lua, input.bValue);
                        break;
                    case DataType::number:
                        lua_pushnumber(_lua, input.numValue);
                        break;
                    case DataType::string:
                        lua_pushstring(_lua, input.sValue.c_str());
                        break;
                }
            }
            int result = lua_pcall(_lua, inputs.getCount(), 0, 0);
            if (result)
            {
                std::string errMsg = "Error executing method " + tableName + "::" +  methodName + ". Reason: " + lua_tostring(_lua, -1);
                LogError(errMsg);
            }
            lua_pop(_lua, 1);
        }
        else
        {
            LogDebug("methodName does not exist, " + tableName + "::" + methodName);
        }
    }
    else
    {
        LogDebug("Unknown error. " + tableName + "::" + methodName);
    }
}

// for now only support one return result
LuaValue ScriptManager::ExecuteTableMethod(std::string tableName, std::string methodName, LuaMethodInputs inputs, DataType returnType)
{
    LuaValue output;

    // assume we won't be resolving a value
    output.type = DataType::noval;

    lua_getglobal(_lua, tableName.c_str());
    if (!lua_isnil(_lua, 0))
    {
        lua_getfield(_lua, -1, methodName.c_str());
        if (lua_isfunction(_lua, -1))
        {
            // set inputs
            for (auto& input: inputs.get())
            {
                switch (input.type)
                {
                    case DataType::nil:
                        lua_pushnil(_lua);
                        break;
                    case DataType::boolean:
                        lua_pushboolean(_lua, input.bValue);
                        break;
                    case DataType::number:
                        lua_pushnumber(_lua, input.numValue);
                        break;
                    case DataType::string:
                        lua_pushstring(_lua, input.sValue.c_str());
                        break;
                }
            }
            int result = lua_pcall(_lua, inputs.getCount(), 1, 0);
            if (result)
            {
                std::string errMsg = "Error executing method " + tableName + "::" +  methodName + ". Reason: " + lua_tostring(_lua, -1);
                LogError(errMsg);
            }

            if (!lua_isnil(_lua, -1))
            {
                if (returnType == DataType::boolean) 
                {
                    bool value = lua_toboolean(_lua, -1);
                    output.bValue = value;
                    output.type = DataType::boolean;
                }
                else if (returnType == DataType::number)
                {
                    double numValue = lua_tonumber(_lua, -1);
                    output.numValue = numValue;
                    output.type = DataType::number;
                }
                else if (returnType == DataType::string)
                {
                    const char* str = lua_tostring(_lua, -1);
                    output.sValue = std::string(str);
                    output.type = DataType::string;
                }
            }
            else
            {
                std::string err = "Error executing method " + std::string(lua_tostring(_lua, -1));
                LogError(err);
            }
            lua_pop(_lua, 1);
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
    return output;
}

ScriptManager::~ScriptManager()
{
    if (_lua)
    {
        lua_close(_lua);
    }
}