#include <string>

#include <SFML/Graphics.hpp>

#ifndef __COIN_HPP__
#define __COIN_HPP__

class Coin {
public:
  Coin(float, const std::string &);
  void draw(sf::RenderWindow &);

private:
  sf::Sprite m_sprite;
  sf::Texture m_texture;
};

#endif