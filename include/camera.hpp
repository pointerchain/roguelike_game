// camera.hpp

#pragma once

#include <SFML/Graphics.hpp>

class Camera {
public:
  Camera(sf::RenderWindow &window);

  void Update(const sf::Vector2f look_position);
  void Draw();

private:
  sf::RenderWindow &window_;
  sf::View view_{};
};