
#include "GameObjectFactory.h"

#include "Utils.h"

namespace Engine
{



void GameObjectFactory::Initialize()
{
    // parse and load all lua scripts
    auto files = GetFiles("scripts");
    for (auto& file : files)
    {
        printf("file %s\n", file.c_str());
    }
    
}

}