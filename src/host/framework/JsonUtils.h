#pragma once

#include "../lib/json/includes/json.h"

namespace Engine
{

bool ParseJsonFile(std::string filename, Json::Value& root);

}