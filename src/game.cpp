// game.cpp

#include "game.hpp"

#include "enemy.hpp"
#include "input.hpp"

Game::Game() {
  for (int i = 0; i < 10; ++i) {
    enemies_.push_back(Enemy({i * 50.f, 50}));
  }
};

void Game::Run() {
  while (window_.isOpen()) {
    ProcessEvents();

    Update();
    Clear();
    Draw();
    Display();
  }
};

void Game::ProcessEvents() {
  sf::Event event;
  while (window_.pollEvent(event)) {
    switch (event.type) {
      case sf::Event::Closed:
        window_.close();
      default:
        break;
    }
  }
}

void Game::Update() {
  const auto dt = clock.restart().asSeconds();

  character_.Update(dt, Input::GetUserInput());
  camera_.Update(window_.getSize(), character_.GetPosition());

  for (auto &enemy : enemies_) {
    enemy.Update(dt, character_.GetPosition(), enemies_);
  }
}

void Game::Draw() {
  map_.Draw(window_);
  character_.Draw(window_);
  camera_.Draw(window_);

  for (auto &enemy : enemies_) {
    enemy.Draw(window_);
  }
}

void Game::Display() { window_.display(); }

void Game::Clear() { window_.clear(); }