// main.cpp

#include <SFML/Graphics.hpp>
#include <print>

#include "game.hpp"

int main() {
  Game game{};
  game.Run();

  std::println("Terminating roguelike game...");

  return 0;
}