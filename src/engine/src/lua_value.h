
#pragma once

#include <string>

// used for inputs and returns
enum class DataType
{
    nil,
    boolean,
    number,
    string,

    // helps when value cannot be resolved
    noval
};

struct LuaValue
{
    DataType type;

    bool bValue;
    double numValue;
    std::string sValue;

    LuaValue() {}
    
    LuaValue(bool value)
    {
        bValue = value;
    }

    LuaValue(double value)
    {
        numValue = value;
    }

    LuaValue(std::string value)
    {
        sValue = value;
    }

    // TODO: figure out to support more complex types
};