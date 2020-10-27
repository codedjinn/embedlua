#pragma once

#include "Vector2.h"

#include <windows.h>

namespace Engine
{

class Player
{
    private:
        float _faceDir;
        Vector2 _startPos;

        HANDLE _handle;
        HANDLE _console;
        DWORD _oldMode;

        void HandleKeys();


    public:
        Player();

        void Update(float time);

        const Vector2 getStartPos() { return _startPos; }
        const float getFaceDir() { return _faceDir; }
};

}