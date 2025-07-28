#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

const int WIDTH = 1024;
const int HEIGHT = 768;

int main(int argc, char **argv) {
  sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}), "Coin Collector");
  window.setFramerateLimit(60);

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }

    window.clear(sf::Color::Green);

    window.display();
  }
  return 0;
}
