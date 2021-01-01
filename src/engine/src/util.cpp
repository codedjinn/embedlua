
#include "util.h"

#include <dirent.h>
#include <fstream>

#include "logger.h"

std::string GetCurDir()
{
    DIR* dir = opendir("c://");
    struct dirent *dent;

    while ((dent = readdir(dir)) != nullptr)
    {
        printf("%s\n", dent->d_name);
    }    
    closedir(dir);

    return std::string("");
}

std::vector<std::string> GetFiles(std::string path)
{
    std::vector<std::string> result;

    DIR* dir;
    dirent* ent;

    // if directory isn't found it will be null
    if ((dir = opendir(path.c_str())) != nullptr)
    {
        while ((ent = readdir(dir)) != nullptr)
        {
            std::string filename(ent->d_name);

            if ((filename.length() == 1 && filename.compare(".") > -1)
                || (filename.length() == 2 && filename.compare("..") > -1))
            {
                continue;
            }

            result.push_back(path + "\\" + filename);
        }
    }

    closedir(dir);

    return result;
}

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