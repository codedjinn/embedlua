#pragma once

#include <vector>

#include "Map.h"
#include "Player.h"

namespace Engine
{

class GameInstance
{

    private:

        bool _isRunning;
        Player* _player;
        Map _map;

    public:

        GameInstance()
        {
            _isRunning = false;
            _player = new Player();
        }

        void Demo();

        void Run();

};

}