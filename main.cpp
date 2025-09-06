
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif

#include <iostream>
#include <memory>

#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>

int main(int argc, char** argv)
{
    auto window = std::make_shared<sf::Window>(sf::VideoMode({800, 600}), "OpenGL 3D Scene");
    window->setActive(true);
    while (window->isOpen())
    {
        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window->close();
        }
        glClearColor(0.f, 0.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glBegin(GL_TRIANGLES);
            glColor3f(1.f, 0.f, 0.f); glVertex3f(-0.5f, -0.5f, 0.f);
            glColor3f(0.f, 1.f, 0.f); glVertex3f(0.5f, -0.5f, 0.f);
            glColor3f(0.f, 0.f, 1.f); glVertex3f(0.f, 0.5f, 0.f);
        glEnd();
        window->display();
    }
    return 0;
}