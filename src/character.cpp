// character.cpp

#include "character.hpp"
#include "config.hpp"

Character::Character(sf::RenderWindow &window) : window_(window) {
  self_.setFillColor(sf::Color::Red);

  self_.setPosition({window_.getSize().x / 2.f, window_.getSize().y / 2.f});
}

void Character::Update(const float dt, const UserInput user_input) {
  velocity_ = user_input.direction * Config::Character::kMoveSpeed;
  distance_ = velocity_ * dt;

  self_.setPosition(self_.getPosition() + distance_);
}

void Character::Draw() { window_.draw(self_); }