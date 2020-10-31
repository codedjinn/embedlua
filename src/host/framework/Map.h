#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include "MapCell.h"

namespace Engine
{

struct MapDefinition
{
    std::string Name;
    int Width;
    int Height;
    bool IsClosed;
    sf::Vector2f PlayerStart;
    
    int CellsCount;
    MapCell* Cells;
};

class Map
{
    private:

        int _length;
        MapCell* _cells;

        MapDefinition _model;

        void Build();

    public:

        const float TileSize = 20.0f;

        void Load(const std::string filename);

        // will need to implement this for actual game
        // void Load(std::string filename);

        const MapCell Get(int x, int y);
        void Set(int x, int y, MapCellType type);

        const int getWidth() { return _model.Width; }
        const int getHeight() { return _model.Height; }

        const sf::Vector2f getPlayerStart() { return _model.PlayerStart; }

        void Draw(float time, sf::RenderWindow& renderer);
};

}