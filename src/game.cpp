// game.cpp

#include "game.hpp"
#include "input.hpp"

Game::Game() {};

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
  camera_.Update(character_.GetPosition());
}

void Game::Draw() {
  camera_.Draw();
  map_.Draw();
  character_.Draw();
}

void Game::Display() { window_.display(); }

void Game::Clear() { window_.clear(); }