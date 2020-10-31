#pragma once

#include <SFML/Graphics.hpp>

namespace Engine
{

class Player
{
    private:
        float _faceDir;
        sf::Vector2f _pos;
        void HandleKeys(float time);

        sf::RectangleShape _shape;
        sf::RectangleShape _pp;

    public:
        Player();

        void Update(float time);
        void Draw(float time, sf::RenderWindow& renderer);

        const sf::Vector2f getPos() { return _pos; }
        void setPos(sf::Vector2f value) 
        { 
            _pos = value;            
        }
        void setPos(float x, float y) { _pos = sf::Vector2f(x,y); }

        const float getFaceDir() { return _faceDir; }
};

}