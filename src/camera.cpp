// camera.cpp

#include "camera.hpp"

Camera::Camera(sf::RenderWindow &window) : window_(window) {
  view_.setSize(window_.getSize().x, window_.getSize().y);
  view_.setCenter(window_.getSize().x / 2.f, window_.getSize().y / 2.f);
}

void Camera::Update(const sf::Vector2f look_position) {
  view_.setSize(window_.getSize().x, window_.getSize().y);
  view_.setCenter(look_position);
}

void Camera::Draw() { window_.setView(view_); }