// camera.cpp

#include "camera.hpp"

Camera::Camera(const sf::Vector2u window_size) {
  Update(window_size, {window_size.x / 2.f, window_size.y / 2.f});
}

void Camera::Update(const sf::Vector2u window_size,
                    const sf::Vector2f look_position) {
  view_.setSize(window_size.x, window_size.y);
  view_.setCenter(look_position);
}

void Camera::Draw(sf::RenderWindow &window) { window.setView(view_); }