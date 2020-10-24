#include "GameObjectFactory.h"

#include "Utils.h"
#include "JsonUtils.h"
#include "Logger.h"

#include "../lib/json/includes/json.h"

namespace Engine
{

void GameObjectFactory::Initialize()
{
    LogInfo("[GameObjectFactory]<Initialize> Enter");

    // should only called once the game is started
    if (_isInitialized)
    {
        LogError("[GameObjectFactory]<Initialize> Already Initialized!");
        return;
    }

    // hate this but we need to log if parsing failed to troubleshoot
    try
    {
        // parse and load all lua scripts
        auto files = GetFiles("objects");
        for (auto& file : files)
        {
            LogInfo("Parsing " + file);
            Json::Value root;
            if (ParseJsonFile(file, root))
            {
                std::string debugMsg("Parsed successfully " + file);
                LogDebug(debugMsg);
            }
        }
    }
    catch(const std::exception& e)
    {
        std::string errMsg("Failed to parse script. Reason - ") ;
        errMsg.append(e.what());
        LogError(errMsg);
    }
    
    _isInitialized = true;

    LogInfo("[GameObjectFactory]<Initialize> Exit");
}

}