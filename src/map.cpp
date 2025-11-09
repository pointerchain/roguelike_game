// map.cpp

#include "map.hpp"
#include "config.hpp"

Map::Map() {
  texture_.loadFromFile("assets/tiles.png");
  tiles_.setPrimitiveType(sf::Quads);

  Load();
}

void Map::Draw(sf::RenderWindow &window) {
  sf::RenderStates render_states{};
  render_states.texture = &texture_;

  window.draw(tiles_, render_states);
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

      // For flat border tile vs bottom border tile
      const int x_texture_offset = y == Config::Map::kMapHeight - 1 ? 32 : 0;
      const int y_texture_offset = Config::Sprite::kSize * 0;

      vertex_tl.texCoords = sf::Vector2f(x_texture_offset, y_texture_offset);
      vertex_tr.texCoords = sf::Vector2f(
          x_texture_offset + Config::Sprite::kSize, y_texture_offset);
      vertex_br.texCoords =
          sf::Vector2f(x_texture_offset + Config::Sprite::kSize,
                       Config::Sprite::kSize + y_texture_offset);
      vertex_bl.texCoords = sf::Vector2f(
          x_texture_offset, Config::Sprite::kSize + y_texture_offset);

      tiles_.append(vertex_tl);
      tiles_.append(vertex_tr);
      tiles_.append(vertex_br);
      tiles_.append(vertex_bl);
    }
  }
}