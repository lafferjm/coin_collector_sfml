#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "game_objects/coin/coin.hpp"

const int WIDTH = 1024;
const int HEIGHT = 768;

int main(int argc, char **argv) {
  sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}), "Coin Collector");
  window.setFramerateLimit(60);

  sf::Clock clock;

  Coin *coin = new Coin(2.f, "assets/sprites/coin.png", 9);

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }

    float delta_time = clock.restart().asSeconds();

    window.clear(sf::Color::Green);

    coin->update(delta_time);
    coin->draw(window);

    window.display();
  }
  return 0;
}
