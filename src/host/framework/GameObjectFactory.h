#pragma once

#include <string>

#include "Lookup.h"
#include "GameObject.h"

namespace Engine
{

class GameObjectFactory
{
    private:

        Lookup _objects;
        bool _isInitialized;

        static GameObjectFactory* _instance;

    public:

        void Initialize();

        GameObject* Create(std::string name);

        static GameObjectFactory& instance();
};

}