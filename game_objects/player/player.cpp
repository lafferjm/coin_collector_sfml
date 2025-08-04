#include "player.hpp"
#include <string>
#include <SFML/Graphics.hpp>

void Player::load_animations() {
    m_animations["idle"] = {};
    m_animations["walk"] = {};

    for (int i = 0; i < 10; i++) {
        m_animations["idle"].push_back(sf::IntRect({i * 32, 0}, {32, 32}));
        m_animations["walk"].push_back(sf::IntRect({i * 32, 64}, {32, 32}));
    }
}

Player::Player(float scale, const std::string &texture_path) : m_sprite(m_texture), m_current_animation("idle"),
                                                               m_current_frame(0), m_frame_duration(1/m_animation_fps),
                                                               m_elapsed_time(0) {
    m_texture = sf::Texture(texture_path, false);
    m_sprite = sf::Sprite(m_texture);
    load_animations();

    m_sprite.setTextureRect(m_animations[m_current_animation].at(0));
    m_sprite.setScale({scale, scale});
}

void Player::draw(sf::RenderWindow &target) const {
    target.draw(m_sprite);
}

void Player::update(const float delta_time) {
    m_elapsed_time += delta_time;
    if (m_elapsed_time > m_frame_duration) {
        m_current_frame = (m_current_frame + 1) % static_cast<int>(m_animations[m_current_animation].size());
        m_elapsed_time = 0.0f;
        m_sprite.setTextureRect(m_animations[m_current_animation].at(m_current_frame));
    }
}