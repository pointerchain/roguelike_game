// input.cpp

#include "input.hpp"

#include <cmath>

namespace Input {

sf::Vector2f GetDirection() {
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

} // namespace Input