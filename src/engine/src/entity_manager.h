

//
// TODO:
// * Figure out how to get around not using singletons...
//

#pragma once

#include <vector>
#include <unordered_map>

#include "util.h"

#include "entity_model.h"
#include "entity.h"

class EntityManager
{

public:

    EntityManager()
    {
        _idCounter = 0;
    }

    // try and change to reference or value type later
    std::pair<bool, const Entity&> CreateEntity(std::string name);

    void Initialize();

private:

    void LoadEntityDefinitions();

    unsigned int _idCounter;

    std::unordered_map<int, Entity*> _entities;
    std::vector<EntityModel> _entityDefinitions;

};