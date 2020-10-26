#include "GameInstance.h"

#include <unistd.h>
#include <chrono>

namespace Engine
{

void GameInstance::Demo()
{
    
}

void GameInstance::Run()
{
    _isRunning = true;

    float acc = 0.0f;
    while (_isRunning)
    {
        _player.Update(0.25f);
        usleep(250000);
    }
}

}