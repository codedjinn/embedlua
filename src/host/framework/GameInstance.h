#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

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

        GameInstance();

        void Demo();

        //void Run();

        void Update(float time);
        void Draw(float time, sf::RenderWindow& renderer);

        void Shutdown();

};

}