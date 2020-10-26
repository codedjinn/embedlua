#pragma once

#include <string>

#include "Vector2.h"

namespace Engine
{

class Map
{
    private:

        int _width;
        int _height;

        Vector2 _playerStart;

    public:

        void Demo();

        // will need to implement this for actual game
        // void Load(std::string filename);

        const int getWidth() { return _width; }
        const int getHeight() { return _height; }
};

}