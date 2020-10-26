#pragma once

#include <string>
#include <vector>

//#include "GameObjectDef.h"

namespace Engine
{

class GameObjectFactory
{
    private:

       // std::vector<GameObjectDef> _definitions;

        //std::map<std::string, std::string> _scripts;
        bool _isInitialized;

    public:

        void Initialize();

        //const GameObject& Create(std::string name);

        // const std::vector<GameObjectDef> getDefinitions()
        // {
        //     return _definitions;
        // }
};

}