#pragma once

namespace Engine
{

// just for POC, handles one key at a time
struct Keyboard
{
    int Key;
    bool IsPressed;
    bool Handled;
};

static Keyboard KeyState;

}