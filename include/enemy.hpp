// enemy.hpp

#pragma once

#include <SFML/Graphics.hpp>

enum class EnemyState { kIdle, kChasing };
class Enemy {
 public:
  Enemy(const sf::Vector2f starting_position);

  sf::Vector2f GetPosition() const;

  void Update(const float dt, const sf::Vector2f character_position,
              const std::vector<Enemy> &enemies);
  void Draw(sf::RenderWindow &window);

 private:
  static sf::Texture texture_;
  sf::Sprite sprite_{};

  EnemyState state_{EnemyState::kIdle};

  sf::Vector2f velocity_{};

  bool CharacterInRange(const sf::Vector2f character_position);
  sf::Vector2f GetDirectionToCharacter(const sf::Vector2f character_position);
};