#pragma once

#include <string>
#include <vector>

#include "lua_value.h"

// probably can do some fancy templating but I like to keep it simple
class LuaMethodInputs
{
private:

    bool _isEmpty;
    std::vector<LuaValue> _params;

public:

    LuaMethodInputs()
    {
        _isEmpty = false;
    }

    void AddNumber(double value)
    {
        LuaValue param;
        param.type = DataType::number;
        param.numValue = value;
        _params.push_back(param);
    }

    void AddBool(bool value)
    {
        LuaValue input;
        input.type = DataType::boolean;
        input.bValue = value;
        _params.push_back(input);
    }

    void AddString(std::string value)
    {
        LuaValue input;
        input.type = DataType::string;
        input.sValue = value;
        _params.push_back(input);
    }

    void AddNil()
    {
        LuaValue input;
        input.type = DataType::nil;
        _params.push_back(input);
    }

    void Clear()
    {
        _params.clear();
    }

    const int getCount()
    {
        return _params.size();
    }

    const std::vector<LuaValue> get()
    {
        return _params;
    }
    
    static LuaMethodInputs Empty() 
    { 
        LuaMethodInputs empty;
        empty._isEmpty = true;
        return empty;
    }

    static bool IsEmpty(LuaMethodInputs instance)
    {
        return instance._isEmpty;
    }
};
