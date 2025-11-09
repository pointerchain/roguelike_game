// game.hpp

#pragma once

#include "camera.hpp"
#include "character.hpp"
#include "config.hpp"
#include "map.hpp"

#include <SFML/Graphics.hpp>

class Game {
public:
  Game();

  void Run();

private:
  sf::RenderWindow window_{
      sf::RenderWindow(sf::VideoMode(Config::Window::kWindowWidth,
                                     Config::Window::kWindowHeight),
                       Config::Window::kName)};
  sf::Clock clock{};

  Camera camera_{window_.getSize()};
  Map map_{};
  Character character_{window_.getSize()};

  void ProcessEvents();
  void Update();
  void Clear();
  void Draw();
  void Display();
};