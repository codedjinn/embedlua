#pragma once

#include <string>
#include <vector>
#include <cstdarg>

#include "../lib/lua/include/lua.hpp"

#include "logger.h"
#include "method_input_builder.h"

class ScriptManager
{

private:

    bool _isInitialized;

    lua_State* _lua;

public:

    ~ScriptManager();

    // Loads all scripts in the 'scripts' directory. 
    // NOTE: Non-recursive for now.
    void Initialize();

    void Load(std::string filename);

    void ExecuteTableMethod(std::string tableName, std::string methodName);
    void ExecuteTableMethod(std::string tableName, std::string methodName, MethodInputBuilder builder);

};