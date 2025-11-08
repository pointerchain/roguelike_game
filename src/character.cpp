#include "character.hpp"

Character::Character(sf::RenderWindow &window) : window_(window) {
  self_.setFillColor(sf::Color::Red);

  self_.setPosition({window_.getSize().x / 2.f, window_.getSize().y / 2.f});
}

void Character::Draw() { window_.draw(self_); }