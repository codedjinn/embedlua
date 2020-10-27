#include "Player.h"

#include <iostream>
#include <cassert>

#include <conio.h>

#include "Keyboard.h"

namespace Engine
{

Player::Player()
{
    _pos.x = 0.0f;
    _pos.y = 0.0f;
}

const int KEY_W = 119;
const int KEY_S = 115;
const int KEY_A = 97;
const int KEY_D = 77;

void Player::HandleKeys()
{
    if (_kbhit() != 0)
    {
        int key = _getch();
        if (key == KEY_W)
        {
            _pos.y += 0.5f;
        }
        else if (key == KEY_S)
        {
            _pos.y -= 0.5f;
        }
        else if (key == KEY_A)
        {
            _pos.x -= 0.5f;
        }
        else if (key == KEY_D)
        {
            _pos.x += 0.5f;
        }
    }
}

void Player::Update(float time)
{
    HandleKeys();
}

}