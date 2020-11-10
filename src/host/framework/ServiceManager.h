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

        ServiceManager();
        ~ServiceManager();

        void Initialize();

        ScriptManager& getScriptMgr();
        GameObjectFactory& getObjectFactory();
};

}