#include "GameObjectFactory.h"

#include "../lib/json/includes/json.h"

#include "Utils.h"
#include "JsonUtils.h"
#include "Logger.h"

namespace Engine
{

void GameObjectFactory::Initialize()
{
    LogInfo("GameObjectFactory::Initialize()");

    auto files = GetFiles("objects");
    for (std::string file : files)
    {
        LogDebug("file: " + file);
        
        Json::Value root;
        if (ParseJsonFile(file, root))
        {
            std::string objName = root.get("name", "").asString();
            if (!objName.empty())
            {
                std::string script = root.get("script", "").asString();
                if (!script.empty())
                {
                    _objects.Add(objName, script);
                }
            }            
        }
    }
}

GameObject* GameObjectFactory::Create(std::string name)
{
    GameObject* newObj = new GameObject();
    newObj->setName(name);

    // check if definition loaded
    auto script = _objects.Get(name);

    LogDebug("Script: " + (script.empty() ? "" : script));

    if (!script.empty())
    {
        newObj->setScript(script);
    }

    return newObj;
}


// void GameObjectFactory::Initialize()
// {
//     LogInfo("[GameObjectFactory]<Initialize> Enter");

//     // should only called once the game is started
//     if (_isInitialized)
//     {
//         LogError("[GameObjectFactory]<Initialize> Already Initialized!");
//         return;
//     }

//     // hate this but we need to log if parsing failed to troubleshoot
//     try
//     {
//         // parse and load all JSON scripts
//         auto files = GetFiles("objects");
//         for (auto& file : files)
//         {
//             LogInfo("Parsing " + file);
//             Json::Value root;
//             if (ParseJsonFile(file, root))
//             {
//                 GameObjectDef def;
//                 def.FromJson(root);
//                 if (!def.IsEmpty())
//                 {
//                     _definitions.push_back(def);
//                 }

//                 std::string debugMsg("Parsed successfully " + file);
//                 LogDebug(debugMsg);
//             }
//         }
//     }
//     catch(const std::exception& e)
//     {
//         std::string errMsg("Failed to parse script. Reason - ");
//         errMsg.append(e.what());
//         LogError(errMsg);
//     }
    
//     _isInitialized = true;

//     LogInfo("[GameObjectFactory]<Initialize> Exit");
// }

}