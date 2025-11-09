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

constexpr float kAcceleration{5250.f};
constexpr float kDrag{8.5f};

constexpr float kDashDefaultSpeed{2750.f};
constexpr float kDashDefaultDuration{0.25f};
constexpr float kDashDefaultCooldown{2.f};

} // namespace Character

namespace Camera {} // namespace Camera

} // namespace Config