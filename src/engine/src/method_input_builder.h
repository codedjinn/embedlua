#pragma once

#include <string>
#include <vector>

// used for inputs and returns
enum class DataType
{
    nil,
    boolean,
    number,
    string
};

// probably can do some fancy templating but I like to keep it simple
struct MethodInput
{
    DataType type;

    bool bValue;
    double numValue;
    std::string sValue;

    // TODO: figure out to support more complex types
};

class MethodInputBuilder
{

private:

    std::vector<MethodInput> _inputs;

public:

    void AddNumber(double value)
    {
        MethodInput input;
        input.type = DataType::number;
        input.numValue = value;
        _inputs.push_back(input);
    }

    void AddBool(bool value)
    {
        MethodInput input;
        input.type = DataType::boolean;
        input.bValue = value;
        _inputs.push_back(input);
    }

    void AddString(std::string value)
    {
        MethodInput input;
        input.type = DataType::string;
        input.sValue = value;
        _inputs.push_back(input);
    }

    void AddNil()
    {
        MethodInput input;
        input.type = DataType::nil;
        _inputs.push_back(input);
    }

    const int getCount()
    {
        return _inputs.size();
    }

    const std::vector<MethodInput> getInputs()
    {
        return _inputs;
    }
};
