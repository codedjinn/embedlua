#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "ServiceManager.h"

#include "Map.h"
#include "Player.h"
#include "GameObject.h"

namespace Engine
{

//
// NOTE: for now, game instance will be passed around for shared global instances
//

class GameInstance
{
    private:

        bool _isRunning;
        std::string _name;
        
        Map* _map;
        Player* _player;
        std::vector<GameObject*> _objects;

        ServiceManager* _services;

    public:

        GameInstance();

        void Initialize(ServiceManager* services);

        void Demo();

        //void Run();

        void Update(float time);
        void Draw(float time, sf::RenderWindow& renderer);

        void Shutdown();

        const std::string getName() { return _name; }

};

}