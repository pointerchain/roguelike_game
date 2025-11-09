// map.hpp

#pragma once

#include <SFML/Graphics.hpp>

class Map {
public:
  Map();

  void Draw(sf::RenderWindow &window);

private:
  sf::Texture texture_{};
  sf::VertexArray tiles_{};

  void Load();
};