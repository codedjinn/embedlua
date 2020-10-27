#include "Map.h"

#include <cassert>

namespace Engine
{

void Map::Demo()
{
    _width = 20;
    _height = 20;

    _length = _width * _height;
    _cells = new MapCell[_length];
}

const MapCell Map::Get(int x, int y)
{
    if ((x < 0 || x > _width - 1)
        || (y < 0 || y > _height - 1))
    {
        assert("Out of bounds to access cell on map");
    }

    return _cells[_width * y + x];
}

void Map::Set(int x, int y, MapCellType type)
{
    _cells[_width * y + x].Type = type;
}

}