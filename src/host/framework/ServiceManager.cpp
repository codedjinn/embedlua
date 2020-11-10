#include "ServiceManager.h"

namespace Engine
{

ServiceManager::ServiceManager()
{
    _script = new ScriptManager();
    _objectFactory = new GameObjectFactory();
}

ServiceManager::~ServiceManager()
{
    if (_script != nullptr)
    {
        delete _script;
        _script = nullptr;
    }
    if (_objectFactory != nullptr)
    {
        delete _objectFactory;
        _objectFactory = nullptr;
    }
}

void ServiceManager::Initialize()
{
    _script->Initialize();
    _objectFactory->Initialize();
}

ScriptManager& ServiceManager::getScriptMgr() { return *_script; }

GameObjectFactory& ServiceManager::getObjectFactory() { return *_objectFactory; }

}