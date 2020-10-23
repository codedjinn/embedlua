#pragma once

#include "GameObject.h"

#include <string>
#include <map>

namespace Engine
{

class GameObjectFactory
{
    private:

        std::map<std::string, std::string> _scripts;

    public:

        void Initialize();

        const GameObject& Create(std::string name);
};

}