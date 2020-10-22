
#pragma once

#include <stdio.h>

#include "vector3.h"


class Entity
{
    private:

        unsigned int id;
        Vector3 pos;
        Vector3 rot;
        const char* script;        

    public:

        Entity()
        {
            printf("[Entity] ctor\n");

            this->script = "some.lua";
        }

        const char* get_script() 
        {
            return this->script;
        }      
};