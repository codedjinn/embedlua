#include "lib/lua/include/lua.hpp"

#include <stdlib.h>
#include <stdio.h>

#include "src/util.h"

#include "src/script_manager.h"

#include "src/entity_manager.h"

int main()
{
    try
    {
        ScriptManager mgr;
        mgr.Initialize();   

        EntityManager entMgr;
        entMgr.Initialize();

        auto entity = entMgr.CreateEntity("basic");
        auto entity1 = entMgr.CreateEntity("basic");
        auto entity2 = entMgr.CreateEntity("basic");
        auto entity3 = entMgr.CreateEntity("basic");

    }
    catch(const std::exception& e)
    {
        LogError(std::string("!!CRITICAL!!") + std::string(e.what()));
    }
    catch (...)
    {
        LogError("!!CRITICAL!! No Reason");
    }

    // mgr.ExecuteTableMethod("ent", "update");

    // LuaMethodInputs inputs;
    // inputs.AddNumber(10.0);
    // inputs.AddString("I am no CHUMP!");

    // mgr.ExecuteTableMethod("ent", "foo", inputs);

    // // need to figure out int and double handling from LUA
    // LuaValue result = mgr.ExecuteTableMethod("ent", "res", LuaMethodInputs(), DataType::number);

    // printf("Result from script %f2.0, \n", result.numValue);

    return 0;
}