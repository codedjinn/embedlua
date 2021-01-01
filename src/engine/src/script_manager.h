#pragma once

#include <string>
#include <vector>
#include <cstdarg>

#include "../lib/lua/include/lua.hpp"

#include "logger.h"
#include "lua_value.h"
#include "lua_method.h"

class ScriptManager
{

private:

    bool _isInitialized;

    lua_State* _lua;
    
    // loads all built-in lua scripts and binds to them
    void InitializeSystem();

public:

    ~ScriptManager();

    // Loads all scripts in the 'scripts' directory. 
    // NOTE: Non-recursive for now.
    void Initialize();

    // DEBUG, shouldn't be in final release
    void Load(std::string filename);

    // TODO: refactor methods to re-use same code
    
    void ExecuteTableMethod(std::string tableName, std::string methodName);
    void ExecuteTableMethod(std::string tableName, std::string methodName, LuaMethodInputs inputs);
    LuaValue ExecuteTableMethod(std::string tableName, std::string methodName, LuaMethodInputs inputs, DataType returnType);

};