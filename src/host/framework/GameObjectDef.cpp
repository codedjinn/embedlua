#include "GameObjectDef.h"

namespace Engine
{

GameObjectDef GameObjectDef::Empty()
{
    auto result = GameObjectDef();
    result._name = std::string("");
    result._script = std::string("");
    return result;
}

bool GameObjectDef::IsEmpty()
{
    return _name.empty() && _script.empty();
}

void GameObjectDef::FromJson(Json::Value root)
{
    _name = std::string(root.get("name", "").asCString());
    _script = std::string(root.get("name", "").asCString());
}

}