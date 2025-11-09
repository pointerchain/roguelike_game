// config.hpp

#pragma once

#include <string>
namespace Config {

namespace Window {

constexpr std::string kName{"Roguelike Game"};

constexpr int kWindowWidth{400};
constexpr int kWindowHeight{1000};

} // namespace Window

namespace Sprite {
constexpr int kSize{32};
}

namespace Map {

constexpr int kTileWidth{Sprite::kSize * 2};
constexpr int kTileHeight{Sprite::kSize * 2};
constexpr int kMapWidth{50};
constexpr int kMapHeight{50};

} // namespace Map

namespace Character {

constexpr float kSpriteScale{2.5f};
constexpr float kMoveSpeed{500.f};

} // namespace Character

namespace Camera {} // namespace Camera

} // namespace Config