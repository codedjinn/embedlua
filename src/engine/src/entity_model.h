#pragma once

#include <string>

struct EntityModel
{
    std::string name;
    std::string script;    

    EntityModel() {}
    EntityModel(std::string nameStr, std::string scriptStr)
    {
        name = nameStr;
        script = scriptStr;
    }
};