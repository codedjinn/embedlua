#include "ScriptManager.h"

#include "../lib/json/includes/json.h"

#include "Logger.h"
#include "Utils.h"
#include "JsonUtils.h"

namespace Engine
{

void ScriptManager::Initialize()
{
    // LogInfo("Loading scripts...");

    // // get all files from script folder
    // auto files = GetFiles("scripts");
    // for (std::string file : files)
    // {
        
    // }

    // LogInfo("Scripts loaded.");
}

void ScriptManager::Load(std::string name)
{
    auto existing = _scripts.find(name);
    if (existing == _scripts.end())
    {
        std::string script_name = this->FindScript(name);
        if (!script_name.empty())
        {
            std::string json = this->GetScript(script_name);
            _scripts.insert(name, json);
        }
    }
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
            std::string objName = root.get("name", "").asString();
            if (objName.compare(name) == 0)
            {
                std::string script = root.get("script", "").asString();
                if (!script.empty())
                {
                    result = this->GetScript(script);
                }
            }            
        }
    }

    return result;
}

std::string ScriptManager::GetScript(std::string filename)
{
    std::string result;

    LogInfo("filename " + filename);

    std::string test_str = "scripts\\" + filename;

      LogInfo("test_str " + test_str);

    // get all files from script folder
    auto files = GetFiles("scripts");
    for (std::string file : files)
    {
        LogInfo("file " + file);
        if (file.compare(test_str) == 0)
        {            
            result = ReadFromFile(file);
        }
    }

    return result;
}

}