#pragma once

#include <string>

#include "MapCell.h"

namespace Engine
{

class Map
{
    private:

        int _width;
        int _height;

        int _length;
        MapCell* _cells;

    public:

        void Demo();

        // will need to implement this for actual game
        // void Load(std::string filename);

        const MapCell Get(int x, int y);
        void Set(int x, int y, MapCellType type);

        const int getWidth() { return _width; }
        const int getHeight() { return _height; }
};

}