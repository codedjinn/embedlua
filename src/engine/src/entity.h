#pragma once

#include <string>
#include <cassert>

class Entity
{
private:

    bool _idSet;
    unsigned int _id;
    std::string _script;

public:

    Entity()
    {
        _idSet = false;
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
    }
    const int getId(unsigned int id)
    {
        return _id;
    }

    static const Entity& Empty()
    {
        return *(new Entity());
    }
};