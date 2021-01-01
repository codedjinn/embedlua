
#include "script_manager.h"

#include <algorithm>

#include "util.h"

const char* System_Script_File = "scripts\\system.lua";

std::vector<std::string> System_Scripts;

void ScriptManager::InitializeSystem()
{
    System_Scripts.push_back(std::string(System_Script_File));

    // if this file isn't available, game should fail
    this->Load(System_Script_File);
}

void ScriptManager::Initialize()
{
    _lua = luaL_newstate();
    luaL_openlibs(_lua);  

    this->InitializeSystem();

    auto files = GetFiles("scripts");
    for (auto& file : files)
    {
        // skip reserved files
        auto result = std::find(System_Scripts.begin(), System_Scripts.end(), file);
        if (result != System_Scripts.end())
        {
            std::string msg = "Skipped system file, '";
            msg.append(file);
            msg.append("'");
            LogDebug(msg);
            continue;
        }
        this->Load(file);
    }
}

void ScriptManager::Load(std::string filename)
{
    LogInfo("Loading script and executing, " + filename);
    int result = luaL_loadfile(_lua, filename.c_str());
    if (result || lua_pcall(_lua, 0, 0, 0))
    {
        std::string errMsg = "Failed to load script, '";
        errMsg.append(filename);
        errMsg.append("', reason: ");
        errMsg.append(lua_tostring(_lua, -1));
        LogError(errMsg);
        lua_pop(_lua, 1);
    }
    else
    {
        LogInfo("SUCCESS");
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
                std::string errMsg = "Coudln't execute";
                errMsg.append(tableName);
                errMsg.append("::");
                errMsg.append(methodName);
                errMsg.append(", reason - ");
                errMsg.append(lua_tostring(_lua, -1));
                LogError(errMsg);
            }
            lua_pop(_lua, 1);
        }
    }
    else
    {
        std::string msg = "Unknown error! ";
        msg.append(tableName);
        msg.append("::");
        msg.append(methodName);
        LogDebug(msg);
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
                std::string errMsg = "Coudln't execute";
                errMsg.append(tableName);
                errMsg.append("::");
                errMsg.append(methodName);
                errMsg.append(", reason - ");
                errMsg.append(lua_tostring(_lua, -1));
                LogError(errMsg);
            }
            lua_pop(_lua, 1);
        }
        else
        {
            std::string msg = "methodName does not exist, ";
            msg.append(tableName);
            msg.append("::");
            msg.append(methodName);
            LogDebug(msg);
        }
    }
    else
    {
        std::string msg = "Unknown error! ";
        msg.append(tableName);
        msg.append("::");
        msg.append(methodName);
        LogDebug(msg);
    }
}

// for now only support one return result
LuaValue ScriptManager::ExecuteTableMethod(std::string tableName, std::string methodName, LuaMethodInputs inputs, DataType returnType)
{
    LuaValue output;

    // we haven't resolved the value yet
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
                std::string errMsg = "Error executing method ";
                errMsg.append(tableName);
                errMsg.append("::");
                errMsg.append(methodName);
                errMsg.append(". Reason: ");
                errMsg.append(lua_tostring(_lua, -1));
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
                std::string err = "Error executing method ";
                err.append(lua_tostring(_lua, -1));
                LogError(err);
            }
            lua_pop(_lua, 1);
        }
        else
        {
            std::string msg = "methodName does not exist, ";
            msg.append(tableName);
            msg.append("::");
            msg.append(methodName);
            LogDebug(msg);
        }        
    }
    else
    {
        std::string msg = "Unknown error.";
        msg.append(tableName);
        msg.append("::");
        msg.append(methodName);
        LogDebug(msg);
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