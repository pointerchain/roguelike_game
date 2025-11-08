#pragma once

#include <SFML/Graphics.hpp>

class Character {
public:
  Character(sf::RenderWindow &window);

  void Move();
  void Update();
  void Draw();

private:
  sf::RenderWindow &window_;
  sf::RectangleShape self_{sf::RectangleShape({40, 40})};

  sf::Vector2f velocity_{};
  sf::Vector2f distance_{};
};