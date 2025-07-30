#include "coin.hpp"
#include <SFML/Graphics.hpp>
#include <string>

Coin::Coin(float scale, const std::string &texturePath)
    : m_texture(), m_sprite(m_texture) {
  m_texture = sf::Texture(texturePath, false, sf::IntRect({0, 0}, {32, 32}));
  m_sprite = sf::Sprite(m_texture);
  m_sprite.setScale({scale, scale});
}

void Coin::draw(sf::RenderWindow &target) { target.draw(m_sprite); }