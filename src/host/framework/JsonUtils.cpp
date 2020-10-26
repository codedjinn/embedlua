#include "JsonUtils.h"

#include <iostream>
#include <fstream>

#include "Logger.h"

namespace Engine
{

bool ParseJsonFile(std::string filename, Json::Value& root)
{
    std::ifstream file (filename, std::ifstream::in);
    if (file.good())
    {
        JSONCPP_STRING err;
        Json::CharReaderBuilder builder;
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



