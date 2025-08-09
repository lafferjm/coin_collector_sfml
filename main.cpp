#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <cmath>
#include <memory>
#include <optional>
#include <random>

#include "game_objects/coin/coin.hpp"
#include "game_objects/player/player.hpp"
#include "utilities/sprite_group/sprite_group.hpp"

constexpr int width = 1024;
constexpr int height = 768;
constexpr int frame_rate = 60;

constexpr float player_speed = 200;

sf::Vector2f normalize(sf::Vector2f move_direction) {
  float length = std::sqrt(move_direction.x * move_direction.x + move_direction.y * move_direction.y);

  if (length != 0.f) {
    move_direction.x /= length;
    move_direction.y /= length;
  }

  return move_direction;
}

int main(int, char **) {
  sf::RenderWindow window(sf::VideoMode({width, height}), "Coin Collector");
  window.setFramerateLimit(frame_rate);

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution x_dist(0.0f, 1024.f - 32.f);
  std::uniform_real_distribution y_dist(0.0f, 768.f - 32.f);

  sf::Clock clock;

  SpriteGroup<Coin> coin_group;

  const auto player = std::make_unique<Player>(5.f, "assets/sprites/player.png");

  for (int i = 0; i < 10; i++) {
    const auto coin = std::make_shared<Coin>(2.f, "assets/sprites/coin.png", 9);
    const float x_position = x_dist(gen);
    const float y_position = y_dist(gen);
    coin->set_position(x_position, y_position);
    coin_group.add(coin);
  }

  while (window.isOpen()) {
    const float delta_time = clock.restart().asSeconds();

    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }

    sf::Vector2f move_direction(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
      move_direction.x -= 1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
      move_direction.x += 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
      move_direction.y -= 1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
      move_direction.y += 1;
    }

    move_direction = normalize(move_direction);

    sf::Vector2f player_direction = move_direction * delta_time * player_speed;

    window.clear(sf::Color::Green);

    player->update(delta_time, player_direction);
    coin_group.update(delta_time);

    player->draw(window);
    coin_group.draw(window);

    window.display();
  }

  return 0;
}
