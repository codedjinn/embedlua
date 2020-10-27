#pragma once

namespace Engine
{

// basic for now
enum class MapCellType
{
    Open,
    Closed
};

// helps describes details about the map
struct MapCell
{
    MapCellType Type;
    int x;
    int y;
};

}


