#pragma once

#include <iostream>
#include <fstream>
#include <string>

const char* read_file(const char* filename)
{
    std::ifstream file ("entity1.json", std::ifstream::in);

    std::string result;
    do
    {
        char ch = file.get();
        result += ch;
    } while (file.good());        
    file.close();

    return result.c_str();
}
