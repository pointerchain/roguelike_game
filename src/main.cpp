// main.cpp

#include "character.hpp"
#include "input.hpp"
#include "map.hpp"

#include <SFML/Graphics.hpp>
#include <print>

void Draw(sf::RenderWindow &window) {
  static sf::Clock clock{};

  static Map map(window);
  static Character character(window);

  const auto dt = clock.restart().asSeconds();

  map.Draw();

  character.Update(dt, {Input::GetDirection()});
  character.Draw();
}

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Roguelike Game");

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

    Draw(window);

    window.display();
  }

  std::println("Terminating roguelike game...");

  return 0;
}