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

        sf::Vector2f _size;
        sf::Vector2f _pos;
        float _rotation;

        // bounding box
        sf::Rect<float> _bbox;

    public:

        GameObject() {}
        //GameObject(GameObject&& ref) {}

        void Initialize();
        void Update(float time);
        void Draw(float time);

        sf::Rect<float> getBoundingBox() { return _bbox; }

        sf::Vector2f getPos() { return _pos; }
        void setPos(sf::Vector2f value) { _pos = value; }
    
    };

}