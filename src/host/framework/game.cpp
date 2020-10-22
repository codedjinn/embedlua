
#include <stdlib.h>
#include <thread>
#include <chrono>

#include "game.h"
#include "logger.h"

namespace engine
{

Game* create_game()
{
    log("Creating Game");
    Game* result = (Game*)malloc(sizeof(Game));
    result->isRunning = true;
    log("Game created");

    return result;
}

void run_game(Game* game)
{
    while (game->isRunning)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

}