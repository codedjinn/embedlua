#pragma once

#include <stdio.h>

namespace engine
{

void log(const char* str)
{
    // for now console
    printf("%d\n", str);

}

}