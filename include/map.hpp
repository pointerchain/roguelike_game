// map.hpp

#pragma once

#include <SFML/Graphics.hpp>

class Map {
public:
  Map(sf::RenderWindow &window);

  void Draw();

private:
  sf::RenderWindow &window_;

  sf::Texture texture_{};
  sf::VertexArray tiles_{};

  void Load();
};