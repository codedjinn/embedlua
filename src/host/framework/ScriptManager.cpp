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

void ScriptManager::ExecuteMethod(std::string name)
{
    LogInfo("ScriptManager::ExecuteMethod");

    lua_getglobal(_lua, name.c_str());
    if (lua_isfunction(_lua, -1))
    {
        LogDebug("Executing function: " + name);
        lua_pcall(_lua, 0, 0, 0);
    }
}

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
    LogDebug("ScriptManager::Load | " + name);
    // std::string script_name = this->FindScript(name);
    // if (!script_name.empty())
    // {
    //     //std::string json = this->GetScript(script_name);
    //     LogDebug("script_name: " + script_name);
    //     // int err_result = luaL_dofile(_lua, script_name.c_str());
    //     // if (err_result)
    //     // {
    //     //     auto err_str = lua_tostring(_lua, -1);
    //     //     printf("LUA ERROR %s\n", err_str);
    //     // }
        
    //         // LogInfo("Scripts loaded.");

    //    // printf("json | %s\n", json.c_str());
    // //    _scripts.insert(name, json);
    
    // }

    // auto existing = _scripts.find(name);
    // if (existing == _scripts.end())
    // {
    //     std::string script_name = this->FindScript(name);
    //     if (!script_name.empty())
    //     {
    //         std::string json = this->GetScript(script_name);
    //         _scripts.insert(name, json);
    //     }
    // }
}

std::string ScriptManager::FindScript(std::string name)
{
    std::string result;

    auto files = GetFiles("objects");
    for (std::string file : files)
    {
        Json::Value root;
        if (ParseJsonFile(file, root))
        {
            std::string scriptName = root.get("script", "").asString();
            if (scriptName.compare(name) == 0)
            {
                //std::string script = root.get("script", "").asString();
                //if (!script.empty())
                {
                    result = this->GetScript(scriptName);
                    break;
                }
            }            
        }
    }

    return result;
}

std::string ScriptManager::GetScript(std::string filename)
{
    std::string result;
    std::string test_str = "scripts\\" + filename;

    // get all files from script folder
    auto files = GetFiles("scripts");
    for (std::string file : files)
    {
        if (file.compare(test_str) == 0)
        {            
            result = ReadFromFile(file);
            break;
        }
    }

    return result;
}

}