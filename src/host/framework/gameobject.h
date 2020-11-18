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
        std::string _name;
        std::string _script;

        sf::Vector2f _size;
        sf::Vector2f _pos;
        float _rotation;

        // bounding box
        sf::Rect<float> _bbox;

        // faster than std::string.empty() check ? test later
        bool _hasScript;

        void* _services;

    public:

        GameObject();

        void Update(float time);
        void Draw(float time);

        sf::Rect<float> getBoundingBox();

        sf::Vector2f getPos();
        void setPos(sf::Vector2f value);

        std::string getName();
        void setName(std::string value);

        std::string getScript();
        void setScript(std::string value);
    };

}