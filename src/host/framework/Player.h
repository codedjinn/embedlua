#pragma once

#include "Vector2.h"

namespace Engine
{

class Player
{
    private:
        Vector2 _startPos;

        void HandleKeys();

    public:

        void Update(float time);
};

}