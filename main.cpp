#include <iostream>
#include <memory>

#include <SFML/Window.hpp>

#include "Window.hpp"

int main(int argc, char** argv)
{
    auto window = InitWindow();
    while (window->isOpen())
    {
        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window->close();
        }
        Render(window);
        window->display();
    }
    return 0;
}