#include "JsonUtils.h"

#include <iostream>
#include <fstream>

#include "Logger.h"

namespace Engine
{

bool ParseJsonFile(std::string filename, Json::Value& root)
{
    Json::CharReaderBuilder builder;

    JSONCPP_STRING err;

    std::ifstream file (filename, std::ifstream::in);
    if (file.good())
    {
        if (Json::parseFromStream(builder, file, &root, &err))
        {
            return true;
        }
        else
        {
            std::string errMsg("Error parsing ");
            errMsg.append(filename);
            errMsg.append(". Reason: ");
            errMsg.append(err);
            
            LogError(errMsg);
        }        
    }
    else
    {
        std::string errMsg("File not found: ");
        LogDebug(errMsg + filename);
    }
        
    return false;
}

}



