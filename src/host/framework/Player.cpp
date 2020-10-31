#include "Player.h"

#include <iostream>
#include <cassert>

#include <SFML/Graphics.hpp>

#include "Keyboard.h"

namespace Engine
{

Player::Player()
{
    _pos.x = 0.0f;
    _pos.y = 0.0f;
    _faceDir = 0.0f;

    _shape = sf::RectangleShape(sf::Vector2f(10, 20));
    _shape.setOrigin(5, 10);
    _shape.setFillColor(sf::Color::Blue);

    _pp = sf::RectangleShape(sf::Vector2f(2,4));
    _pp.setOrigin(1, 2);
}

void Player::HandleKeys(float time)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        _faceDir -= 0.1f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        _faceDir += 0.1f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        _pos.x = _pos.x + (_pos.x * _faceDir * time);
        _pos.y = _pos.y - (_pos.y * _faceDir * time);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
    }
}

void Player::Update(float time)
{
    //HandleKeys(time);printf("Player.setPos %.2f %.2f", value.x, value.y);
}

bool once1 = true;

void Player::Draw(float time, sf::RenderWindow& renderer)
{
    _shape.setPosition(_pos);
    _shape.setRotation(_faceDir);

    _pp.setPosition(_pos);

    renderer.draw(_shape);
    renderer.draw(_pp);
}

}