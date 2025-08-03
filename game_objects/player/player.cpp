#include "player.hpp"
#include <string>
#include <SFML/Graphics.hpp>

Player::Player(float scale, const std::string &texture_path, int frame_count) : m_sprite(m_texture), m_frame_count(10) {
    m_texture = sf::Texture(texture_path, false);
    m_sprite = sf::Sprite(m_texture);
    m_sprite.setTextureRect(sf::IntRect({ 0, 0 }, { 32, 32 }));
    m_sprite.setScale({scale, scale});
}

void Player::draw(sf::RenderWindow &target) const {
    target.draw(m_sprite);
}