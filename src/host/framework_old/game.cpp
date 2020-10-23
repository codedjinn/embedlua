
// #include <stdlib.h>
// #include <thread>
// #include <chrono>

// #include "game.h"
// #include "logger.h"

// namespace engine
// {

// Game* create_game()
// {
//     log("[create_game]");
//     Game* result = (Game*)malloc(sizeof(Game));
//     result->isRunning = true;
//     log("[create_game] finished");

//     return result;
// }

// void run_game(Game* game)
// {
//     log("[run_game]");
//     while (game->isRunning)
//     {
//         // loop and update ?
//         std::this_thread::sleep_for(std::chrono::milliseconds(250));
//     }
// }

// }