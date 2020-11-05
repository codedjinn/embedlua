#pragma once

#include <string>

#include "Lookup.h"
#include "GameObject.h"

namespace Engine
{

class GameObjectFactory
{
    private:

      Lookup _definitions;

      //  std::map<char*, char*> _definitions;

        //std::map<std::string, std::string> _scripts;
        bool _isInitialized;

    public:

        void Initialize();

        bool Create(std::string name, GameObject& obj);

        // const std::vector<GameObjectDef> getDefinitions()
        // {
        //     return _definitions;
        // }
};

}