#include "lib/lua/include/lua.hpp"

#include <stdlib.h>
#include <stdio.h>
#include <thread>
#include <conio.h>

#include "src/util.h"
#include "src/logger.h"
#include "src/services.h"
#include "src/entity_manager.h"

int main()
{
    try
    {
        // ScriptManager mgr;
        // mgr.Initialize();   

        // EntityManager entMgr;
        // entMgr.Initialize();

        Services services;
        services.Add(new EntityManager());
        services.Initialize();

        auto entMgr = (EntityManager*)services.GetService(ServiceType::Entity);
        //services.Add(nullptr);

      //  services.getEntities().CreateEntity("basic");

        // auto entity = entMgr.CreateEntity("basic");
        // auto entity1 = entMgr.CreateEntity("basic");
        // auto entity2 = entMgr.CreateEntity("basic");
        // auto entity3 = entMgr.CreateEntity("basic");

        while (true)
        {
            // while we don't have full system, give CPU a breather
            std::chrono::duration<double, std::milli> time(50);

            services.Update(0.13333);

            if (_kbhit())
            {
                break;
            }


            std::this_thread::sleep_for(time);
        }

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