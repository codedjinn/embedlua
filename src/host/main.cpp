
#include <stdio.h>
#include <iostream>

#include "framework/Utils.h"
#include "framework/Logger.h"

int main()
{
    Engine::LogInfo("Starting Engine...");

    // limit try/catch usage
    try
    {
    }
    catch(const std::exception& e)
    {
        // C/C++ people have funny method names...
        printf("Exception: %d\n", e.what());
    }
    
    return 0;
}