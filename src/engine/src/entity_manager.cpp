
#include "entity_manager.h"

#include "../lib/json/includes/json.h"

#include "util.h"
#include "logger.h"

void EntityManager::Initialize()
{
    this->LoadEntityDefinitions();
}

void EntityManager::LoadEntityDefinitions()
{
    auto files = GetFiles("objects");
    for (auto& file : files)
    {
        Json::Value root;
        if (ParseJsonFile(file, root))
        {
            std::string objName = root.get("name", "").asString();
            if (!objName.empty())
            {
                std::string script = root.get("script", "").asString();
                if (!script.empty())
                {
                    auto model = EntityModel(objName, script);
                    _entityDefinitions.push_back(model);
                }
            }
        }
    }
}

std::pair<bool, const Entity&> EntityManager::CreateEntity(std::string name)
{
    bool found = false;
    EntityModel model;

    // look for definition
    for (auto& def : _entityDefinitions)
    {
        if (def.name.compare(name) == 0)
        {
            model = def;
            found = true;
            break;
        }
    }

    if (!found)
    {
        std::string msg = "Couldn't load entity '";
        msg.append(name);
        msg.append("'");
        LogError(msg);
        return std::pair<bool, const Entity&>(false, Entity::Empty());
    }

    int id = _idCounter++;
    Entity* newEntity = new Entity();
    newEntity->setId(id);
    newEntity->setScript(model.script);
    newEntity->setName(model.name);

    // dumb but ok for now
    if (_idCounter > 20480)
    {
        LogError("Entity count exceeded 20480");
        assert(0);
    }

    auto newValue = std::unordered_map<int, Entity*>::value_type(id, newEntity);
    _entities.insert(newValue);

    return std::pair<bool, const Entity&>(false, *newEntity);
}


void EntityManager::Update(float time)
{
    for (auto& pair : _entities)
    {
        Entity& ent = *pair.second;
        
        
    }
    
}
