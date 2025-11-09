// character.hpp

#pragma once

#include "config.hpp"
#include "input.hpp"

#include <SFML/Graphics.hpp>

enum class CharacterState { kNormal, kDashing };
class Character {
public:
  Character(const sf::Vector2u window_size);

  sf::Vector2f GetPosition() const;

  void Update(const float dt, const UserInput user_input);
  void Draw(sf::RenderWindow &window);

private:
  sf::Texture texture_{};
  sf::Sprite sprite_{};

  CharacterState state_{CharacterState::kNormal};

  sf::Vector2f velocity_{};

  float dash_speed_{Config::Character::kDashDefaultSpeed};
  float dash_duration_{Config::Character::kDashDefaultDuration};
  float dash_cooldown_{Config::Character::kDashDefaultCooldown};
  sf::Vector2f dash_direction_{};
  float dash_timer_{};
  float dash_cooldown_timer_{dash_cooldown_};
};