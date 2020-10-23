#pragma once

#include <string>

namespace Engine
{

//
// don't instantiate directly, do via the factory
//
class GameObject
{
    private:
    
        // will be set by the engine
        int _id;
        std::string _script;

    public:

        void Initialize();
        void Update(float time);

        
};

}