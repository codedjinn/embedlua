#pragma once

#include <SFML/Graphics.hpp>

namespace Engine
{

class Player
{
    private:
        float _faceDir;
        sf::Vector2f _pos;
        void HandleKeys();

    public:
        Player();

        void Update(float time);
        void Draw(float time, sf::RenderWindow& renderer);

        const sf::Vector2f getPos() { return _pos; }
        const float getFaceDir() { return _faceDir; }
};

}