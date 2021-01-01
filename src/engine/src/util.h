#pragma once

#include <string>
#include <vector>

#include "../lib/json/includes/json.h"

std::string GetCurDir();
std::vector<std::string> GetFiles(std::string path);

bool ParseJsonFile(std::string filename, Json::Value& root);

enum class Result
{
    Success,
    Fail
};