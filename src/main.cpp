// main.cpp

#include "character.hpp"

#include <SFML/Graphics.hpp>
#include <cmath>
#include <print>

sf::Vector2f getDirection() {
  sf::Vector2f direction{};

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    --direction.y;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    --direction.x;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    ++direction.y;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    ++direction.x;
  }

  const auto magnitude =
      std::sqrt(direction.x * direction.x + direction.y * direction.y);

  if (magnitude != 0) {
    direction.x /= magnitude;
    direction.y /= magnitude;
  }

  return direction;
}

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Roguelike Game");
  sf::Clock clock{};

  Character character(window);

  while (window.isOpen()) {
    const auto dt = clock.restart().asSeconds();

    sf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        window.close();
      default:
        break;
      }
    }

    window.clear();

    character.Update(dt, {getDirection()});
    character.Draw();

    window.display();
  }

  std::println("Terminating roguelike game...");

  return 0;
}