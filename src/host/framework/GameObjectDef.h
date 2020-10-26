#pragma once

#include <string>

#include "../lib/json/includes/json.h"

namespace Engine
{

class GameObjectDef
{
    private:
        std::string _name;
        std::string _script; 

    public:
        GameObjectDef()
        {
            _name = std::string("");
            _script = std::string("");
        }

        void FromJson(Json::Value root);
        bool IsEmpty();
        static GameObjectDef Empty();

        std::string getName() { return _name; }
        std::string getScript() { return _script; }
};

}