
#include <stdio.h>
#include <iostream>

#include "framework/Utils.h"
#include "framework/Logger.h"

#include "framework/GameObjectFactory.h"

int main()
{
    Engine::LogInfo("Starting Engine...");

    // limit try/catch usage
    try
    { 
        // usefull if class fails to create new instance then we know where execution stopped
        Engine::LogInfo("Creating GameObjectFactory...");

        auto* factory = new Engine::GameObjectFactory();
        factory->Initialize();
    }
    catch(const std::exception& e)
    {
        // C/C++ people have funny method names...
        printf("Exception: %d\n", e.what());
    }
    
    return 0;
}