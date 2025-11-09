// main.cpp

#include "game.hpp"
#include <SFML/Graphics.hpp>
#include <print>

int main() {
  Game game{};
  game.Run();

  std::println("Terminating roguelike game...");

  return 0;
}