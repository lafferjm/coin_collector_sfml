#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <memory>
#include <optional>

#include "game_objects/coin/coin.hpp"
#include "utilities/sprite_group/sprite_group.hpp"

constexpr int width = 1024;
constexpr int height = 768;
constexpr int frame_rate = 60;

int main(int, char **) {
  sf::RenderWindow window(sf::VideoMode({width, height}), "Coin Collector");
  window.setFramerateLimit(frame_rate);

  sf::Clock clock;

  SpriteGroup<Coin> coin_group;

  for (int i = 0; i < 10; i++) {
    const auto coin = std::make_shared<Coin>(2.f, "assets/sprites/coin.png", 9);
    coin->set_position(static_cast<float>(i) * 32, 0);
    coin_group.add(coin);
  }

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }

    const float delta_time = clock.restart().asSeconds();

    window.clear(sf::Color::Green);

    coin_group.update(delta_time);
    coin_group.draw(window);

    window.display();
  }
  return 0;
}
