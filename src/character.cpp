// character.cpp

#include "character.hpp"
#include "config.hpp"

Character::Character(const sf::Vector2u window_size){
  texture_.loadFromFile("assets/rogues.png");
  sprite_.setTexture(texture_);
  sprite_.setTextureRect(
      {Config::Sprite::kSize, 0, Config::Sprite::kSize, Config::Sprite::kSize});

  sprite_.setScale(
      {Config::Character::kSpriteScale, Config::Character::kSpriteScale});
  sprite_.setOrigin({Config::Sprite::kSize / 2.f, Config::Sprite::kSize / 2.f});
  sprite_.setPosition({window_size.x / 2.f, window_size.y / 2.f});
}

sf::Vector2f Character::GetPosition() const { return sprite_.getPosition(); }

void Character::Update(const float dt, const UserInput user_input) {

  switch (state_) {
  case CharacterState::kNormal: {
    const auto acceleration =
        user_input.direction * Config::Character::kAcceleration;
    const auto friction = -velocity_ * Config::Character::kDrag;

    velocity_ += (acceleration + friction) * dt;

    if (user_input.direction.x != 0) {
      if (user_input.direction.x > 0) {
        sprite_.setScale({-Config::Character::kSpriteScale,
                          Config::Character::kSpriteScale});
      } else {
        sprite_.setScale(
            {Config::Character::kSpriteScale, Config::Character::kSpriteScale});
      }
    }

    if (user_input.dash_requested && user_input.direction != sf::Vector2f{} &&
        dash_cooldown_timer_ >= dash_cooldown_) {
      dash_direction_ = user_input.direction;
      dash_cooldown_timer_ = 0;
      state_ = CharacterState::kDashing;
    }

    dash_cooldown_timer_ += dt;

    break;
  }
  case CharacterState::kDashing: {
    velocity_ = dash_direction_ * dash_speed_;

    if (dash_timer_ >= dash_duration_) {
      dash_timer_ = 0;
      velocity_ = dash_direction_ * (dash_speed_ / 5.f);
      state_ = CharacterState::kNormal;
    }

    dash_timer_ += dt;

    break;
  }
  }

  sprite_.setPosition(sprite_.getPosition() + velocity_ * dt);
}

void Character::Draw(sf::RenderWindow &window) { window.draw(sprite_); }