#include "Map.h"

#include <cassert>

#include "Logger.h"
#include "JsonUtils.h"

namespace Engine
{

    Map::Map(ServiceManager *services)
    {
        _services = services;
    }

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
                (x == 0 || y == 0 || x == 19 || y == 19))
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

    LogInfo("Map::Load | " + filename);

    if (!ParseJsonFile(filename, root))
    {
        LogError("Couldn't parse map " + filename);
        return;
    }

    _model.Name = root.get("name", "<no_name_found>").asString();
    _model.IsClosed = root.get("closedMap", "true").asBool();
    _model.Width = root.get("width", "0").asInt();
    _model.Height = root.get("height", "0").asInt();

    _length = _model.Width * _model.Height;

    int px = root["player_start"][0].asInt();
    int py = root["player_start"][1].asInt();

    _model.PlayerStart = sf::Vector2f((float)px * TileSize, (float)py * TileSize);

    this->LoadCells(root);

    this->LoadObjects(root);

    this->Build();
}

void Map::LoadObjects(Json::Value root)
{
    auto scriptMgr = _services->getScriptMgr();
    auto objFactory = _services->getObjectFactory();

    const Json::Value objects = root["objects"];
    for (int i = 0; i < objects.size(); i++)
    {
        const Json::Value cur = objects[i];

        const std::string name = cur.get("name", "").asString();
        LogDebug("Map::Load | object [name] " + name);
        if (!name.empty())
        {
            GameObject* obj = objFactory.Create(name);
            obj->Initialize(_services);

            // let script manager handle the script
            if (!obj->getScript().empty())
            {
                scriptMgr.Load(obj->getScript());
            }

            // set position in world
            auto tmp = cur["pos"];
            if (!tmp.empty())
            {
                float x = tmp[0].asFloat() * Map::TileSize;
                float y = tmp[1].asFloat() * Map::TileSize;
                auto vec = sf::Vector2f(x,y);
                obj->setPos(vec);
            }

            _objects.push_back(obj);

            LogDebug("Map::Load | object added");
        }
        else
        {
            LogError("Object with no name found. " + name);
        }
    }
}

void Map::LoadCells(Json::Value root)
{
    const Json::Value cells = root["cells"];
    _model.Cells = new MapCell[cells.size()];
    _model.CellsCount = cells.size();
    for (int i = 0; i < cells.size(); i++)
    {
        MapCell cell;

        const Json::Value cur = cells[i];
        const std::string type = cur.get("type", "").asString();

        if (type == "Wall")
        {
            cell.Type = MapCellType::Wall;
        }
        else
        {
            cell.Type = MapCellType::Floor;
        }

        cell.x = cur["pos"][0].asInt();
        cell.y = cur["pos"][1].asInt();

        _model.Cells[i] = cell;
    }

    LogInfo("Map::Load | Cells Loaded");
}

const MapCell Map::Get(int x, int y)
{
    if ((x < 0 || x > _model.Width - 1) || (y < 0 || y > _model.Height - 1))
    {
        assert("Out of bounds to access cell on map");
    }

    return _cells[_model.Width * y + x];
}

void Map::Set(int x, int y, MapCellType type)
{
    _cells[_model.Width * y + x].Type = type;
}

void Map::Update(float time)
{
    for (auto obj : _objects)
    {
      //  obj->Update(time);
    }
}

void Map::Draw(float time, sf::RenderWindow &renderer)
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
            shape.setPosition(sf::Vector2f(rx, ry));
            renderer.draw(shape);
        }

        x++;
        if (x > _model.Width - 1)
        {
            x = 0;
            y++;
        }
    }

    for (auto obj : _objects)
    {
        sf::CircleShape shape(10.0f);
        shape.setPosition(obj->getPos());
        shape.setFillColor(sf::Color::Red);
        renderer.draw(shape);
    }
}

} // namespace Engine