// enemy.cpp

#include "enemy.hpp"

#include <cmath>
#include <vector>

#include "config.hpp"

sf::Texture Enemy::texture_{};

Enemy::Enemy(const sf::Vector2f starting_position) {
  if (texture_.getSize().x == 0) {
    texture_.loadFromFile("assets/monsters.png");
  }
  sprite_.setTexture(texture_);
  sprite_.setTextureRect({Config::Sprite::kSize, 0, Config::Sprite::kSize, Config::Sprite::kSize});

  sprite_.setScale({Config::Enemy::kSpriteScale, Config::Enemy::kSpriteScale});
  sprite_.setOrigin({Config::Sprite::kSize / 2.f, Config::Sprite::kSize / 2.f});
  sprite_.setPosition(starting_position);
}

sf::Vector2f Enemy::GetPosition() const { return sprite_.getPosition(); }

void Enemy::Update(const float dt, const sf::Vector2f character_position,
                   const std::vector<Enemy>& enemies) {
  switch (state_) {
    case EnemyState::kIdle: {
      if (CharacterInRange(character_position)) {
        state_ = EnemyState::kChasing;
      }
      velocity_ = {};
      break;
    }
    case EnemyState::kChasing: {
      const auto direction = GetDirectionToCharacter(character_position);
      const auto acceleration = direction * Config::Enemy::kAcceleration;
      const auto friction = -velocity_ * Config::Enemy::kDrag;

      sf::Vector2f separation_force{};
      const auto desired_separation = Config::Sprite::kSize * Config::Enemy::kSpriteScale;
      int neighbors_count{};

      for (const auto& other_enemy : enemies) {
        if (&other_enemy == this) {
          continue;
        }

        const auto diff = GetPosition() - other_enemy.GetPosition();
        const float distance = hypot(diff.x, diff.y);

        if (distance < desired_separation && distance > 0) {
          const auto flee_direction = diff / distance;
          const auto separation_strength = Config::Enemy::kAcceleration * 7.5f;

          separation_force += flee_direction * separation_strength / distance;
          ++neighbors_count;
        }
      }

      if (neighbors_count > 0) {
        separation_force /= static_cast<float>(neighbors_count);
      }

      velocity_ += (acceleration + separation_force + friction) * dt;

      if (direction.x != 0) {
        if (direction.x > 0) {
          sprite_.setScale({-Config::Enemy::kSpriteScale, Config::Enemy::kSpriteScale});
        } else {
          sprite_.setScale({Config::Enemy::kSpriteScale, Config::Enemy::kSpriteScale});
        }
      }

      if (!CharacterInRange(character_position)) {
        state_ = EnemyState::kIdle;
      }
      break;
    }
  }

  auto next_position = sprite_.getPosition() + velocity_ * dt;

  const auto x_border_position = Config::Map::kMapWidth * Config::Map::kTileWidth;
  const auto y_border_position =
      Config::Map::kMapHeight * Config::Map::kTileHeight - Config::Map::kTileWidth;

  if (next_position.x < 0) {
    next_position.x = 0;
  } else if (next_position.x > x_border_position) {
    next_position.x = x_border_position;
  }
  if (next_position.y < 0) {
    next_position.y = 0;
  } else if (next_position.y > y_border_position) {
    next_position.y = y_border_position;
  }

  sprite_.setPosition(next_position);
}

void Enemy::Draw(sf::RenderWindow& window) { window.draw(sprite_); }

bool Enemy::CharacterInRange(const sf::Vector2f character_position) {
  const auto aggro_threshold_sq = Config::Enemy::kAggroRange * Config::Enemy::kAggroRange;
  const auto diff = GetPosition() - character_position;
  const auto distance_to_character_sq = diff.x * diff.x + diff.y * diff.y;

  return distance_to_character_sq <= aggro_threshold_sq;
}

sf::Vector2f Enemy::GetDirectionToCharacter(const sf::Vector2f character_position) {
  auto direction = character_position - GetPosition();
  const auto magnitude = std::hypot(direction.x, direction.y);
  if (magnitude != 0) {
    direction.x /= magnitude;
    direction.y /= magnitude;
  }

  return direction;
}