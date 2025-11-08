// main.cpp

#include "character.hpp"
#include "input.hpp"

#include <SFML/Graphics.hpp>
#include <print>

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

    character.Update(dt, {Input::GetDirection()});
    character.Draw();

    window.display();
  }

  std::println("Terminating roguelike game...");

  return 0;
}