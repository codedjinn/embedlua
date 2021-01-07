

//
// TODO:
// * Figure out how to get around not using singletons...
//

#pragma once

#include <vector>
#include <unordered_map>

#include "util.h"

#include "service_base.h"

#include "entity_model.h"
#include "entity.h"

class EntityManager : public ServiceBase
{

public:

    EntityManager()
    {
        _idCounter = 0;
    }

    // try and change to reference or value type later
    std::pair<bool, const Entity&> CreateEntity(std::string name);

    void Initialize() override;
    void Update(float time) override;

    const int getId() override { return 0; }

private:

    void LoadEntityDefinitions();

    unsigned int _idCounter;

    std::unordered_map<int, Entity*> _entities;
    std::vector<EntityModel> _entityDefinitions;
};