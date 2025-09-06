#pragma once

#include <SFML/Window.hpp>
#include <memory>

std::shared_ptr<sf::Window> InitWindow();

void Render(std::shared_ptr<sf::Window> window);