#pragma once

#include <string>

#include <SFML/Graphics.hpp>

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

        // bounding box
        sf::Rect<float> _bbox;

    public:

        void Initialize();
        void Update(float time);
        void Draw(float time);

        sf::Rect<float> getBoundingBox() { return _bbox; }
    
    };

}