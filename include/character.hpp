// character.hpp

#pragma once

#include <SFML/Graphics.hpp>
struct UserInput {
  sf::Vector2f direction;
};
class Character {
public:
  Character(sf::RenderWindow &window);

  sf::Vector2f GetPosition() const;

  void Update(const float dt, const UserInput user_input);
  void Draw();

private:
  sf::RenderWindow &window_;
  sf::Texture texture_{};
  sf::Sprite sprite_{};

  sf::Vector2f velocity_{};
};