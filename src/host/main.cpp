
#include <stdio.h>
#include <iostream>

#include "framework/game.h"

int main()
{
    // limit try/catch usage
    try
    {
        engine::Game* game = engine::create_game();
        engine::run_game(game);
    }
    catch(const std::exception& e)
    {

    }

    
    return 0;
}