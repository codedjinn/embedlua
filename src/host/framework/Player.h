#pragma once

#include "Vector2.h"

namespace Engine
{

class Player
{
    private:

        float _faceDir;
        Vector2 _pos;

        void HandleKeys();


    public:
        Player();

        void Update(float time);

        const Vector2 getPos() { return _pos; }
        const float getFaceDir() { return _faceDir; }
};

}