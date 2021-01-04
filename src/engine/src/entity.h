#pragma once

#include <string>
#include <cassert>

#include <SFML/Graphics.hpp>

class Entity
{
private:

    bool _idSet;
    unsigned int _id;
    std::string _name;
    std::string _script;

    bool _isEnabled;
    sf::Vector2<float> _pos;
    sf::Vector2<float> _scale;
    float _rotation;

public:

    Entity()
    {
        _idSet = false;
        _scale = sf::Vector2<float>(1.0f, 1.0f);
    }

    // time is in seconds
    //void Update(const float time);

    // 'getters' and 'setters' special naming case
    void setId(const unsigned int id)
    {
        // help detect any weird bugs
        if (_idSet)
        {
          //  LogError("Entity cannot be assigned an id twice!");
            assert(0);
        }
        _id = id;
        _idSet = true;
    }
    const int getId(unsigned int id)
    {
        return _id;
    }

    void setScript(const std::string value)
    {
        _script = value;
    }
    const std::string getScript()
    {
        return _script;
    }

    void setName(const std::string value)
    {
        _name = value;
    }
    const std::string getName()
    {
        return _name;
    }

    void setPos(sf::Vector2<float> value)
    {
        _pos = value;
    }
    void setPos(float x, float y)
    {
        _pos.x = x;
        _pos.y = y;
    }
    const sf::Vector2<float> getPos() { return _pos; }

    void setRotation(float value)
    {
        _rotation = value;
    }
    const float getRotation() { return _rotation; }


    // TODO: Fix this for future (bad)
    static const Entity& Empty()
    {
        return *(new Entity());
    }
};