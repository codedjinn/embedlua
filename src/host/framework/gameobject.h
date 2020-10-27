#pragma once

#include <string>

#include "Vector2.h"

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

        Vector2 _pos;
        // needed for collisions
        float _size;

        

    public:

        void Initialize();
        void Update(float time);

        
};

}