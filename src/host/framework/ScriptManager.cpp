#include "ScriptManager.h"

#include "Logger.h"
#include "Utils.h"

namespace Engine
{

void ScriptManager::Initialize()
{
    LogInfo("Loading scripts...");

    // get all files from script folder
    auto files = GetFiles("scripts");
    for (std::string file : files)
    {
        
    }

    LogInfo("Scripts loaded.");
}

}