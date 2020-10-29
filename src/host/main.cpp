
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
        
        sf::RenderWindow window(sf::VideoMode(800, 600), "Embed");

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            game.Update(0);

            window.clear();

            game.Draw(0, window);

            // sf::RectangleShape rect(sf::Vector2f(120, 50));
            // rect.setSize(sf::Vector2f(100,100));
            // rect.setFillColor(sf::Color::Blue);
            // rect.setPosition(sf::Vector2f(40,40));
            // window.draw(rect);

            window.display();
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