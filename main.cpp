#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "game_objects/coin/coin.hpp"

const int WIDTH = 1024;
const int HEIGHT = 768;

int main(int argc, char **argv) {
  sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}), "Coin Collector");
  window.setFramerateLimit(60);

  sf::Texture coinTexture("assets/sprites/coin.png", false,
                          sf::IntRect({0, 0}, {32, 32}));
  sf::Sprite sprite(coinTexture);
  sprite.scale({2.f, 2.f});

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }

    window.clear(sf::Color::Green);

    window.draw(sprite);

    window.display();
  }
  return 0;
}
