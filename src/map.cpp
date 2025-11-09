// map.cpp

#include "map.hpp"
#include "config.hpp"

Map::Map(sf::RenderWindow &window) : window_(window) {
  texture_.loadFromFile("assets/tiles.png");
  tiles_.setPrimitiveType(sf::Quads);

  Load();
}

void Map::Draw() {
  sf::RenderStates render_states{};
  render_states.texture = &texture_;

  window_.draw(tiles_, render_states);
}

void Map::Load() {
  for (int x = 0; x < Config::Map::kMapWidth; ++x) {
    const int x_offset{x * Config::Map::kTileWidth};
    for (int y = 0; y < Config::Map::kMapHeight; ++y) {
      const int y_offset{y * Config::Map::kTileHeight};
      sf::Vertex vertex_tl(sf::Vector2f(x_offset, y_offset));
      sf::Vertex vertex_tr(
          sf::Vector2f(x_offset + Config::Map::kTileWidth, y_offset));
      sf::Vertex vertex_br(sf::Vector2f(x_offset + Config::Map::kTileWidth,
                                        y_offset + Config::Map::kTileHeight));
      sf::Vertex vertex_bl(
          sf::Vector2f(x_offset, y_offset + Config::Map::kTileHeight));

      vertex_tl.texCoords = sf::Vector2f(0, 0);
      vertex_tr.texCoords = sf::Vector2f(Config::Sprite::kSize, 0);
      vertex_br.texCoords =
          sf::Vector2f(Config::Sprite::kSize, Config::Sprite::kSize);
      vertex_bl.texCoords = sf::Vector2f(0, Config::Sprite::kSize);

      tiles_.append(vertex_tl);
      tiles_.append(vertex_tr);
      tiles_.append(vertex_br);
      tiles_.append(vertex_bl);
    }
  }
}