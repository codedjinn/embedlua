#include "GameObject.h"

namespace Engine
{

GameObject::GameObject()
{
    _pos = sf::Vector2f(0.0, 0.0);
    _size = sf::Vector2f(0.0, 0.0);
}

void GameObject::Initialize()
{
}

void GameObject::Update(float time)
{
}

void GameObject::Draw(float time)
{
}

sf::Rect<float> GameObject::getBoundingBox() { return _bbox; }

sf::Vector2f GameObject::getPos() { return _pos; }
void GameObject::setPos(sf::Vector2f value) 
{
    _pos.x = value.x;
    _pos.y = value.y;
}

std::string GameObject::getName() { return _name; }
void GameObject::setName(std::string value) { _name = value; }


std::string GameObject::getScript() { return _script; }
void GameObject::setScript(std::string value) { _script = value; }

}