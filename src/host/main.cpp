
#include <stdio.h>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "framework/Utils.h"
#include "framework/Logger.h"

#include "framework/GameInstance.h"

int main()
{
    Engine::LogInfo("Starting Engine...");

    // limit try/catch usage
    try
    {
        Engine::GameInstance game;
        game.Demo();
        
        sf::RenderWindow window(sf::VideoMode(800, 600), "Embed");

        int i = 0;
        float fps = 0;
        float time = 0;
        long framesAcc = 0;
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            // float time = sf::Clock::getElapsedTime().asSeconds();
            // if (time > 1.0f)
            // {
            //     fps = 1.0f / (float)framesAcc;
            // }
            // framesAcc++;

            // printf("FPS: %.4f", fps);
           /// auto start = Clock::now();
            // float timeDiff = (curTime.asSeconds() - prevTime.asSeconds());
            // fps = 1.0f / timeDiff;

            // i++;
            // if (i < 100)
            // {        
            //     printf("seconds %.2f\n", curTime.asSeconds());
            //     printf("timeDiff %.2f\n", timeDiff);
            // }

            game.Update(0.0f);

            window.clear();

            game.Draw(0.0f, window);

            // sf::RectangleShape rect(sf::Vector2f(120, 50));
            // rect.setSize(sf::Vector2f(100,100));
            // rect.setFillColor(sf::Color::Blue);
            // rect.setPosition(sf::Vector2f(40,40));
            // window.draw(rect);

            window.display();

          //  auto end = Clock::now();
           // printf("time %.10f", std::chrono::duration_cast<std::chrono::nanoseconds>(Clock::now()).count());
           // printf("time %.10f", std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
        }

        // Engine::GameInstance game;
        // game.Demo();
        // game.Run();
        // game.Shutdown();
        // usefull if class fails to create new instance then we know where execution stopped
        // Engine::LogInfo("Creating GameObjectFactory...");

        // // auto* factory = new Engine::GameObjectFactory();
        // // factory->Initialize();

        // for (auto def : factory->getDefinitions())
        // {
        //     LogInfo("Name " + def.getName());
        // }
    }
    catch(const std::exception& e)
    {
        // C/C++ people have funny method names...
        printf("Exception: %d\n", e.what());
    }
    
    printf("\nEXIT\n");

    return 0;
}