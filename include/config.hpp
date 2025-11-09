// config.hpp

#pragma once

namespace Config {

namespace Sprite {
constexpr int kSize{32};
}

namespace Character {

constexpr float kSpriteScale{2.5f};
constexpr float kMoveSpeed{500.f};

} // namespace Character

namespace Map {

constexpr int kTileWidth{32};
constexpr int kTileHeight{32};
constexpr int kMapWidth{50};
constexpr int kMapHeight{50};

} // namespace Map

} // namespace Config