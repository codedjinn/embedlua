#pragma once

#include "ScriptManager.h"

namespace Engine
{

class ServiceManager
{
    private:
        ScriptManager* _script;

    public:

        ServiceManager()
        {
            _script = new ScriptManager();
        }

        const ScriptManager& getScriptMgr() { return *_script; }
};

}