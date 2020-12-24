#include "lib/lua/include/lua.hpp"

#include <stdlib.h>
#include <stdio.h>

#include "src/script_manager.h"

int main()
{
    ScriptManager mgr;
    mgr.Initialize();
    mgr.Load("entity1.lua");
    mgr.ExecuteTableMethod("ent", "update");

    LuaMethodInputs inputs;
    inputs.AddNumber(10.0);
    inputs.AddString("pew pew pew");

    mgr.ExecuteTableMethod("ent", "foo", inputs);

    LuaValue result = mgr.ExecuteTableMethod("ent", "res", LuaMethodInputs(), DataType::number);

    printf("Result from script %f2.0, \n", result.numValue);

    return 0;
}