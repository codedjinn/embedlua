#pragma once

namespace Engine
{

// basic for now
enum class MapCellType
{
    Floor = 0,
    Wall = 1
};

// helps describes details about the map
struct MapCell
{
    MapCellType Type;
    int x;
    int y;
};

}


