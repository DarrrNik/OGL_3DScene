#include "Window.hpp"

#include <memory>

#include <OpenGL/gl.h>

#include <SFML/Window.hpp>

std::shared_ptr<sf::Window> InitWindow()
{
    auto window = std::make_shared<sf::Window>(sf::VideoMode({800, 600}), "OpenGL 3D Scene");
    window->setActive(true);
    return window;
}

void Render(std::shared_ptr<sf::Window> window)
{
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f); glVertex3f(-0.5f, -0.5f, 0.f);
        glColor3f(0.f, 1.f, 0.f); glVertex3f(0.5f, -0.5f, 0.f);
        glColor3f(0.f, 0.f, 1.f); glVertex3f(0.f, 0.5f, 0.f);
    glEnd();
}
