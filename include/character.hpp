// character.hpp

#pragma once

#include <SFML/Graphics.hpp>
struct UserInput {
  sf::Vector2f direction;
};
class Character {
public:
  Character(sf::RenderWindow &window);

  void Update(const float dt, const UserInput user_input);
  void Draw();

private:
  sf::RenderWindow &window_;
  sf::RectangleShape self_{sf::RectangleShape({40, 40})};

  sf::Vector2f velocity_{};
};