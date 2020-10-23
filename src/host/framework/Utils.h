#pragma once

#include <tuple>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <dirent.h>

namespace Engine
{

// TODO: Return error ?
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
            result.push_back(std::string(ent->d_name));
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