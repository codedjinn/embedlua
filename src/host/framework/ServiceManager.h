#pragma once

#include "ScriptManager.h"
#include "GameObjectFactory.h"

namespace Engine
{

class ServiceManager
{
    private:
        ScriptManager* _script;
        GameObjectFactory* _objectFactory;

    public:

        ServiceManager()
        {
            _script = new ScriptManager();
            _objectFactory = new GameObjectFactory();
        }

        ~ServiceManager()
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

        ScriptManager& getScriptMgr() { return *_script; }

        GameObjectFactory& getObjectFactory() { return *_objectFactory; }
};

}