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

    int x = 0;
    int y = 0;
    for (int i = 0; i < _length; i++)
    {
        if (x == 0)
        {
            _cells[i].Type = MapCellType::Wall;
        }

        if (x > _width - 1)
        {
            x = 0;
            y++;
        }
    }
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

void Map::Draw(float time, sf::RenderWindow& renderer)
{
    int x = 0;
    int y = 0;
    for (int i = 0; i < _length; i++)
    {
        auto cell = _cells[i];
        if (cell.Type == MapCellType::Wall)
        {
            float rx = (float)x * Map::TileSize;
            float ry = (float)y * Map::TileSize;

            // sf::RectangleShape shape(sf::Vector2f(Map::TileSize, Map::TileSize));
            // shape.setOutlineColor(sf::Color::White);
            // shape.setPosition(sf::Vector2f(rx,ry));
            // renderer.draw(shape);
        }
        if (x > _width - 1)
        {
            x = 0;
            y++;
        }
    }
}

}