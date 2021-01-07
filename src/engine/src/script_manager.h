#pragma once

#include <string>
#include <map>

#include "../lib/lua/include/lua.hpp"

#include "logger.h"
#include "service_base.h"
#include "lua_value.h"
#include "lua_method.h"

class ScriptManager : public ServiceBase
{

public:

    ~ScriptManager();

    // Loads all scripts in the 'scripts' directory. 
    // NOTE: Non-recursive for now.
    void Initialize() override;

    void LoadScripts();

    // DEBUG, shouldn't be in final release
    void Load(std::string filename);

    // TODO: refactor methods to re-use same code
    
    void ExecuteTableMethod(std::string tableName, std::string methodName);
    void ExecuteTableMethod(std::string tableName, std::string methodName, LuaMethodInputs inputs);
    LuaValue ExecuteTableMethod(std::string tableName, std::string methodName, LuaMethodInputs inputs, DataType returnType);

    void LinkMethod(std::string name, lua_CFunction funcPtr);

    void Update(float time) override {}

    const int getId() override { return 1; }

    int test(lua_State* lua)
    {
        printf("testing!!");
        return 0;
    }

private:

    bool _isInitialized;
    lua_State* _lua;

    std::map<std::string, lua_CFunction> _linkedMethods;

    // loads all built-in lua scripts and binds to them
    void LoadSystemScripts();
};