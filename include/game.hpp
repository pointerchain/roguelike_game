// game.hpp

#pragma once

#include <SFML/Graphics.hpp>

#include "camera.hpp"
#include "character.hpp"
#include "config.hpp"
#include "enemy.hpp"
#include "map.hpp"

class Game {
 public:
  Game();

  void Run();

 private:
  sf::RenderWindow window_{
      sf::RenderWindow(sf::VideoMode(Config::Window::kWindowWidth, Config::Window::kWindowHeight),
                       Config::Window::kName)};
  sf::Clock clock{};

  Map map_{};
  Character character_{window_.getSize()};
  Camera camera_{window_.getSize()};
  std::vector< Enemy> enemies_;

  void ProcessEvents();
  void Update();
  void Clear();
  void Draw();
  void Display();
};