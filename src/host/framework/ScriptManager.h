#pragma once

#include <string>
#include <vector>

#include "../lib/lua/include/lua.hpp"

namespace Engine
{

//
// TODO: Priority now is to load and reload while in runtime.  Optimize later
//

class ScriptManager
{
    private:

        static ScriptManager* _instance;

        bool _isInitialized;

        lua_State* _lua;

        // std::string FindScript(std::string name);
        // std::string GetScript(std::string filename);

    public:

        ScriptManager();
        ~ScriptManager();
        
        // initialization loads script from the 'script' directory
        void Initialize();

        void Load(std::string name);

        void ExecuteTableMethod(const char* tableName, 
                                const char* methodName);

        void ExecuteTableMethod(const char* tableName, 
                                const char* methodName,
                                std::vector<void*> &inputs);                                

        void ExecuteTableMethod(const char* tableName, 
                                const char* methodName,
                                std::vector<void*> &inputs,
                                std::vector<void*> &returns);

        static ScriptManager& instance();
        
};


}