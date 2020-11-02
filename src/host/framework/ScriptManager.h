#pragma once

#include <map>

namespace Engine
{

class ScriptManager
{
    private:

        std::map<std::string, std::string> _scripts;

    public:

        // initialization loads script from the 'script' directory
        void Initialize();


};

}