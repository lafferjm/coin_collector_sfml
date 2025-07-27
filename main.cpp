#include <iostream>

#include <SFML/Window.hpp>

const int WIDTH = 1024;
const int HEIGHT = 768;

int main(int argc, char **argv) {
  sf::Window window(sf::VideoMode({WIDTH, HEIGHT}), "Coin Collector");

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }
  }
  return 0;
}
