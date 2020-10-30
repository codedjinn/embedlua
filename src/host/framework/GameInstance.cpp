#include "GameInstance.h"

#include <chrono>
#include <thread>

#include <conio.h>

#include "Keyboard.h"

namespace Engine
{

GameInstance::GameInstance()
{
    _isRunning = false;
    _player = new Player();
}

void GameInstance::Demo()
{
    // GameObject* obj = new GameObject();
    // obj->Initialize();
    // _objects.push_back(obj);
    _player->setPos(100.0f,100.0f);

    _map = new Map();
    _map->Demo();
}

void GameInstance::Update(float time)
{
    _player->Update(time);

    for (auto obj : _objects)
    {
        obj->Update(time);
    }
}

void GameInstance::Draw(float time, sf::RenderWindow& renderer)
{
    _map->Draw(time, renderer);
    _player->Draw(time, renderer);
}

// void GameInstance::Draw(float time);
// {
//     _player->Draw(time);
// }

// void GameInstance::Run()
// {
//     _isRunning = true;

//     float acc = 0.0f;
//     while (_isRunning)
//     {
//         // if (_kbhit() != 0)
//         // {
//         //     if (_getch() == 27)
//         //     {
//         //         _isRunning = false;
//         //     }
//         // }
        
//         // player gets one frame up on everything else
//         _player->Update(0.025f);

//         for (auto& cur : _objects)
//         {
//             cur->Update(0.025f);
//         }

//         std::this_thread::sleep_for(std::chrono::milliseconds(25));
//     }
// }

void GameInstance::Shutdown()
{
    //_isRunning = false;

    if (_map != nullptr)
    {
        delete _map;
        _map = nullptr;
    }
    if (_player != nullptr)
    {
        delete _player;
        _player = nullptr;
    }
    if (!_objects.empty())
    {
        unsigned int len = _objects.size();
        for (int i = 0; i < len; i++)
        {
            auto cur = _objects.at(i);
            delete cur;
            cur = nullptr;
        }
    }
}

}