#include "ScriptManager.h"

#include "../lib/json/includes/json.h"

#include "Logger.h"
#include "Utils.h"
#include "JsonUtils.h"

namespace Engine
{

ScriptManager::ScriptManager()
{
    _isInitialized = false;
}

ScriptManager::~ScriptManager()
{
    if (_lua != nullptr)
    {
        lua_close(_lua);
    }
}

//  
void ScriptManager::Initialize()
{
    if (_isInitialized)
    {
        LogDebug("ScriptManager::Initalize called more than once");
        return;
    }
    LogInfo("ScriptManager::Initialize | creating Lua state object");

    _lua = luaL_newstate();
    luaL_openlibs(_lua);

    _isInitialized = true;
    
    LogInfo("ScriptManager::Initialize | DONE");
}

void ScriptManager::Load(std::string name)
{
    LogDebug("<ScriptManager::Load> " + name);

    std::string fullpath = "scripts/" + name;
    int err_result = luaL_dofile(_lua, fullpath.c_str());
    if (err_result)
    {
        auto err_str = lua_tostring(_lua, -1);
        lua_pop(_lua, 1);
        LogError("Error loading LUA script. Reason - " + std::string(err_str));
        return;
    }
    else
    {
        LogDebug("<ScriptManager::Load> Loaded");
    }

 //   lua_pop(_lua, -1);
    // lua_getglobal(_lua, "ent");
    // lua_getfield(_lua, -1, "update");
    // if (lua_isfunction(_lua, -1))
    // {        
    //     lua_pushinteger(_lua, 10);
    //     auto err_result = lua_pcall(_lua, 1, 0, 0);

    //     if (err_result)
    //     {
    //         auto err_str = lua_tostring(_lua, -1);
    //         LogError("Error executing function. Reason - " + std::string(err_str));
    //     }

    // }
    // else if (lua_istable(_lua, -1))
    // {
    //     LogDebug("ITS A TABLE!");
    // }
    // else
    // {
    //     LogDebug("DON'T KNOW!");
    // }
    
}

void ScriptManager::ExecuteTableMethod(const char* tableName, const char* methodName)
{
    LogDebug("ScriptManager::ExecuteTableMethod " + std::string(tableName) + "." + std::string(methodName));

    lua_State* lua = luaL_newstate();

    luaL_dofile(lua, "scripts/entity1.lua");

    // int err_result = luaL_dofile(lua, "scripts/entity1.lua");
    // if (err_result)
    // {
    //     auto err_str = lua_tostring(lua, -1);
    //     lua_pop(lua, 1);
    //     LogError("Error loading LUA script. Reason - " + std::string(err_str));
    //     return;
    // }

    // err_result = lua_getglobal(lua, tableName);
    // if (err_result)
    // {
    //     auto err_str = lua_tostring(lua, -1);
    //     LogDebug("Error executing method. Reason - " + std::string(err_str));
    //     lua_pop(lua, -1);
    //     return;
    // }
    
    // if (lua_istable(lua, -1))
    // {
    //     LogDebug("istable");

    //     lua_getfield(lua, -1, methodName);
    //     if (lua_isfunction(lua, -1))
    //     {
    //         LogDebug("isfunction");
    //         auto err_result = lua_pcall(lua, 0, 0, 0);
    //         if (err_result)
    //         {
    //             auto err_str = lua_tostring(lua, -1);
    //             LogError("Error executing function " + std::string(err_str));
    //         }
    //     }
    //     else
    //     {
    //         LogDebug("Did not find function on table, " + std::string(methodName));
    //     }
        
    // }
    // else
    // {
    //     LogDebug("Expected table " + std::string(tableName));
    // }
}

void ScriptManager::ExecuteTableMethod(const char* tableName, const char* methodName, std::vector<void*> &inputs)
{
    lua_getglobal(_lua, tableName);
    if (lua_istable(_lua, -1))
    {
        lua_getfield(_lua, -1, methodName);
        if (lua_isfunction(_lua, -1))
        {
            
        }
        else
        {
            LogDebug("Did not find function on table, " + std::string(methodName));
        }
        
    }
    else
    {
        LogDebug("Expected table " + std::string(tableName));
    }
}

// std::string ScriptManager::FindScript(std::string name)
// {
//     std::string result;

//     auto files = GetFiles("objects");
//     for (std::string file : files)
//     {
//         Json::Value root;
//         if (ParseJsonFile(file, root))
//         {
//             std::string scriptName = root.get("script", "").asString();
//             if (scriptName.compare(name) == 0)
//             {
//                 //std::string script = root.get("script", "").asString();
//                 //if (!script.empty())
//                 {
//                     result = this->GetScript(scriptName);
//                     break;
//                 }
//             }            
//         }
//     }

//     return result;
// }

// std::string ScriptManager::GetScript(std::string filename)
// {
//     std::string result;
//     std::string test_str = "scripts\\" + filename;

//     // get all files from script folder
//     auto files = GetFiles("scripts");
//     for (std::string file : files)
//     {
//         if (file.compare(test_str) == 0)
//         {            
//             result = ReadFromFile(file);
//             break;
//         }
//     }

//     return result;
// }



ScriptManager* ScriptManager::_instance = nullptr;
ScriptManager& ScriptManager::instance()
{
    if (ScriptManager::_instance == nullptr)
    {
        LogDebug("ScriptManager CREATED");
        ScriptManager::_instance = new ScriptManager();
    }
    return *ScriptManager::_instance;
}

}