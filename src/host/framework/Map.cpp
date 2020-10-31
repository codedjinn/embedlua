#include "Map.h"

#include <cassert>

#include "../lib/json/includes/json.h"

#include "Logger.h"
#include "JsonUtils.h"

namespace Engine
{

// void Map::Demo()
// {
//     _width = 20;
//     _height = 20;

//     _length = _width * _height;
//     _cells = new MapCell[_length];

//     int x = 0;
//     int y = 0;
//     for (int i = 0; i < _length; i++)
//     {
//         MapCell cell;
//         cell.x = x;
//         cell.y = y;
//         if (x == 0
//             || y == 0
//             || x == 19
//             || y == 19)
//         {
//             cell.Type = MapCellType::Wall;
//         }
//         else
//         {
//             cell.Type = MapCellType::Floor;
//         }        
//         _cells[i] = cell;

//         x++;
//         if (x > _width - 1)
//         {
//             x = 0;
//             y++;
//         }
//     }
// }

void Map::Build()
{
    _cells = new MapCell[_length];

    int x = 0;
    int y = 0;
    for (int i = 0; i < _length; i++)
    {
        MapCell cell;
        cell.x = x;
        cell.y = y;
        if (_model.IsClosed &&
            (x == 0
            || y == 0
            || x == 19
            || y == 19) )
        {
            cell.Type = MapCellType::Wall;
        }
        else
        {
            cell.Type = MapCellType::Floor;
        }

        // improve later
        for (int j = 0; j < _model.CellsCount; j++)
        {
            auto cur = _model.Cells[j];
            if (cur.x == x && cur.y == y)
            {
                cell.Type = cur.Type;
            }
        }

        _cells[i] = cell;

        x++;
        if (x > _model.Width - 1)
        {
            x = 0;
            y++;
        }
    }
}

void Map::Load(const std::string filename)
{
    Json::Value root;

    if (!ParseJsonFile(filename, root))
    {
        printf("Something went wrong!");
        return;
    }

    _model.Name = root.get("name", "<no_name_found>").asString();
    _model.IsClosed = root.get("closedMap", "true").asBool();
    _model.Width = root.get("width", "0").asInt();
    _model.Height = root.get("height", "0").asInt();

    _length = _model.Width * _model.Height;
    
    int px = root["player_start"][0].asInt();
    int py = root["player_start"][1].asInt();

    _model.PlayerStart  = sf::Vector2f((float)px * TileSize, (float)py * TileSize);

    printf("p x: %.2f", _model.PlayerStart.x);

    const Json::Value cells = root["cells"];
    _model.Cells = new MapCell[cells.size()];
    _model.CellsCount = cells.size();
    for (int i = 0; i < cells.size(); i++)
    {
        MapCell cell;

        const Json::Value obj = cells[i];
        const std::string type = obj.get("type", "").asString();
        
        if (type == "Wall")
        {   
            cell.Type = MapCellType::Wall;
        }
        else
        {
            cell.Type = MapCellType::Floor;
        }

        cell.x = obj["pos"][0].asInt();
        cell.y = obj["pos"][1].asInt();

        _model.Cells[i] = cell;
    }

    this->Build();
}

const MapCell Map::Get(int x, int y)
{
    if ((x < 0 || x > _model.Width - 1)
        || (y < 0 || y > _model.Height - 1))
    {
        assert("Out of bounds to access cell on map");
    }

    return _cells[_model.Width * y + x];
}

void Map::Set(int x, int y, MapCellType type)
{
    _cells[_model.Width * y + x].Type = type;
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
            
            sf::RectangleShape shape(sf::Vector2f(Map::TileSize, Map::TileSize));
            shape.setOutlineColor(sf::Color::White);
            shape.setOutlineThickness(0.2f);
            shape.setPosition(sf::Vector2f(rx,ry));
            renderer.draw(shape);
        }

        x++;
        if (x > _model.Width - 1)
        {
            x = 0;
            y++;
        }
    }
}

}