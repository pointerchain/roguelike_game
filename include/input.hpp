// input.hpp

#pragma once

#include <SFML/Graphics.hpp>

struct UserInput {
  const sf::Vector2f direction;
  const bool dash_requested;
};
namespace Input {

UserInput GetUserInput();

}