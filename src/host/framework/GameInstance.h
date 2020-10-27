#pragma once

#include <vector>

#include "Map.h"
#include "Player.h"
#include "GameObject.h"

namespace Engine
{

class GameInstance
{

    private:

        bool _isRunning;
        
        Map* _map;
        Player* _player;
        std::vector<GameObject*> _objects;        

    public:

        GameInstance()
        {
            _isRunning = false;
            _player = new Player();
        }

        void Demo();

        void Run();

        void Shutdown();

};

}