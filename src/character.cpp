// character.cpp

#include "character.hpp"
#include "config.hpp"

Character::Character(sf::RenderWindow &window) : window_(window) {
  texture_.loadFromFile("assets/rogues.png");
  sprite_.setTexture(texture_);
  sprite_.setTextureRect({32, 0, 32, 32});

  sprite_.setScale(
      {Config::Character::kSpriteScale, Config::Character::kSpriteScale});
  sprite_.setOrigin({32 / 2.f, 32 / 2.f});
  sprite_.setPosition({window_.getSize().x / 2.f, window_.getSize().y / 2.f});
}

void Character::Update(const float dt, const UserInput user_input) {
  velocity_ = user_input.direction * Config::Character::kMoveSpeed;
  const auto distance_ = velocity_ * dt;

  if (user_input.direction.x != 0) {
    if (user_input.direction.x > 0) {
      sprite_.setScale(
          {-Config::Character::kSpriteScale, Config::Character::kSpriteScale});
    } else {
      sprite_.setScale(
          {Config::Character::kSpriteScale, Config::Character::kSpriteScale});
    }
  }

  sprite_.setPosition(sprite_.getPosition() + distance_);
}

void Character::Draw() { window_.draw(sprite_); }