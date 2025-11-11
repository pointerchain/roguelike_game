// camera.hpp

#pragma once

#include <SFML/Graphics.hpp>

class Camera {
 public:
  Camera(const sf::Vector2u window_size);

  void Update(const sf::Vector2u window_size, const sf::Vector2f look_position);
  void Draw(sf::RenderWindow &window);

 private:
  sf::View view_{};
};