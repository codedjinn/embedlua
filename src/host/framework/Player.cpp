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
}

const int KEY_W = 119;
const int KEY_S = 115;
const int KEY_A = 97;
const int KEY_D = 77;

void Player::HandleKeys()
{
}

void Player::Update(float time)
{
    //HandleKeys();
}

void Player::Draw(float time, sf::RenderWindow& renderer)
{
    auto rect = sf::RectangleShape(sf::Vector2f(10, 20));
    rect.setPosition(_pos);
    rect.setRotation(_faceDir);
    rect.setOutlineColor(sf::Color::Cyan);
    renderer.draw(rect);
}

}