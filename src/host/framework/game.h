#pragma once

namespace engine
{

struct Game
{
    int id;
    bool isRunning;
};

Game* create_game();
void run_game(Game* game);

}
