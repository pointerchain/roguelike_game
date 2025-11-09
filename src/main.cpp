// main.cpp

#include "camera.hpp"
#include "character.hpp"
#include "config.hpp"
#include "input.hpp"
#include "map.hpp"

#include <SFML/Graphics.hpp>
#include <print>

void Draw(sf::RenderWindow &window) {
  static sf::Clock clock{};

  static Camera camera(window);
  static Map map(window);
  static Character character(window);

  const auto dt = clock.restart().asSeconds();

  character.Update(dt, {Input::GetDirection()});
  camera.Update(character.GetPosition());

  camera.Draw();
  map.Draw();
  character.Draw();
}

int main() {
  sf::RenderWindow window(sf::VideoMode(Config::Window::kWindowWidth,
                                        Config::Window::kWindowHeight),
                          "Roguelike Game");

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