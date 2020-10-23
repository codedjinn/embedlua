#pragma once

#include <string>
#include <vector>

namespace Engine
{

std::vector<std::string> GetFiles(std::string path);

std::string ReadFromFile(std::string filename);

}