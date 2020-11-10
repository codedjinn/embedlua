#pragma once

#include <string>

#include "../lib/lua/include/lua.hpp"

namespace Engine
{

//
// TODO: Priority now is to load and reload while in runtime.  Optimize later
//

class ScriptManager
{
    private:
        lua_State* _lua;

        std::string FindScript(std::string name);
        std::string GetScript(std::string filename);

    public:

        ~ScriptManager();
        
        // initialization loads script from the 'script' directory
        void Initialize();

        void Load(std::string name);
        
};

}