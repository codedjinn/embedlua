#pragma once

#include <map>
#include <string>

namespace Engine
{

//
// TODO: Priority now is to load and reload while in runtime.  Optimize later
//

class ScriptManager
{
    private:

        std::map<std::string, std::string> _scripts;

        std::string FindScript(std::string name);
        std::string GetScript(std::string filename);

    public:

        // initialization loads script from the 'script' directory
        void Initialize();

        void Load(std::string name);
};

}