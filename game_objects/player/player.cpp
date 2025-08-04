#include "player.hpp"
#include <string>
#include <SFML/Graphics.hpp>

Player::Player(float scale, const std::string &texture_path) : m_sprite(m_texture) {
    m_texture = sf::Texture(texture_path, false);
    m_sprite = sf::Sprite(m_texture);
    load_animations();

    m_sprite.setTextureRect(m_animations["idle"].at(0));
    m_sprite.setScale({scale, scale});

}

void Player::draw(sf::RenderWindow &target) const {
    target.draw(m_sprite);
}

void Player::load_animations() {
    m_animations["idle"] = {};
    m_animations["walk"] = {};

    for (int i = 0; i < 10; i++) {
        m_animations["idle"].push_back(sf::IntRect({ i * 32, 0 }, {32, 32}));
        m_animations["walk"].push_back(sf::IntRect({ i * 32, 64}, { 32, 32}));
    }

}