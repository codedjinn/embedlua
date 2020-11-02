#include "Utils.h"

#include <iostream>
#include <fstream>

#include <dirent.h>

#include "Logger.h"

namespace Engine
{
    
// TODO: Return error ?
std::vector<std::string> GetFiles(std::string path)
{
    std::vector<std::string> result;

    DIR* dir;
    dirent* ent;

    LogInfo(path);

    // if directory isn't found it will be null
    if ((dir = opendir(path.c_str())) != nullptr)
    {
        LogInfo("dir found");
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

// TODO: Probably simpler more efficient way, revisit later
std::string ReadFromFile(std::string filename)
{
    std::ifstream file (filename, std::ifstream::in);

    if (file.fail())
    {
        return std::string();
    }

    std::string result;
    
    do
    {
        char ch = file.get();
        result += ch;
    } while (file.good());

    file.close();

    return result;
}

}