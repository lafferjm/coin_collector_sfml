#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>

#include "game_objects/coin/coin.hpp"
#include "utilities/sprite_group/sprite_group.hpp"

const int WIDTH = 1024;
const int HEIGHT = 768;

int main(int argc, char **argv) {
  sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}), "Coin Collector");
  window.setFramerateLimit(60);

  sf::Clock clock;

  SpriteGroup<Coin *> coin_group;

  for (int i = 0; i < 10; i++) {
    Coin *coin = new Coin(2.f, "assets/sprites/coin.png", 9);
    coin->set_position(i * 32, 0);
    coin_group.add(coin);
  }

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }

    float delta_time = clock.restart().asSeconds();

    window.clear(sf::Color::Green);

    coin_group.update(delta_time);
    coin_group.draw(window);

    window.display();
  }
  return 0;
}
