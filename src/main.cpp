#include "character.hpp"

#include <SFML/Graphics.hpp>
#include <print>

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Roguelike Game");

  Character character(window);

  while (window.isOpen()) {
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

    character.Draw();

    window.display();
  }

  std::println("Terminating roguelike game...");

  return 0;
}