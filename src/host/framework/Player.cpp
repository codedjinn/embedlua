#include "Player.h"

#include <iostream>
#include <cassert>


namespace Engine
{

Player::Player()
{
    _handle = GetStdHandle(STD_OUTPUT_HANDLE);
    if (_handle == INVALID_HANDLE_VALUE)
    {
        assert("Couldn't handle keyboard input");
    }

    if (!GetConsoleMode(_handle, &_oldMode))
    {
        assert("No old mode!?");
    }
}

void Player::HandleKeys()
{
    DWORD numRead, i;
    INPUT_RECORD inBuf[128];
    int counter = 0;

    while (!counter)
    {
        if (!ReadConsoleInput(_handle, inBuf, 128, &numRead))
        {
            assert("no read console input");
        }

        for (int i = 0; i < numRead; i++)
        {
            INPUT_RECORD cur = inBuf[i];
            switch (cur.EventType)
            {
                case KEY_EVENT:
                    KEY_EVENT_RECORD key = cur.Event.KeyEvent;
                    if (key.wVirtualKeyCode == 57 && key.bKeyDown == true)
                    {
                        // move forward!
                        printf("going forward!");
                    }
                    break;
            }
        }
    } 
}


void Player::Update(float time)
{
    HandleKeys();
}

}