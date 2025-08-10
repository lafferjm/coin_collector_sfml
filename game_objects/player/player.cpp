#include "player.hpp"
#include <string>
#include <SFML/Graphics.hpp>

void Player::load_animations() {
    m_animations[Animation::IDLE] = {};
    m_animations[Animation::WALK] = {};

    for (int i = 0; i < 10; i++) {
        m_animations[Animation::IDLE].push_back(sf::IntRect({i * 32, 0}, {32, 32}));
        m_animations[Animation::WALK].push_back(sf::IntRect({i * 32, 64}, {32, 32}));
    }
}

void Player::set_animation(const Animation animation) {
    m_current_animation = animation;
    m_current_frame = 0.f;
    m_elapsed_time = 0.f;
}

Player::Player(float scale, const std::string &texture_path) : m_sprite(m_texture),
                                                               m_current_animation(Animation::IDLE),
                                                               m_current_frame(0),
                                                               m_frame_duration(1 / m_animation_fps),
                                                               m_elapsed_time(0) {
    m_texture = sf::Texture(texture_path, false);
    m_sprite = sf::Sprite(m_texture);
    load_animations();

    m_sprite.setTextureRect(m_animations[m_current_animation].at(0));
    m_sprite.setScale({scale, scale});

    const sf::FloatRect bounds = m_sprite.getLocalBounds();
    m_sprite.setOrigin(sf::Vector2f(bounds.size.x / 2.f, bounds.size.y / 2.f));

    m_sprite.setPosition(sf::Vector2f(50.f, 100.f));
}

void Player::draw(sf::RenderWindow &target) const {
    target.draw(m_sprite);
}

void Player::update(const float delta_time, const sf::Vector2f move_direction) {
    if (m_current_animation == Animation::IDLE && move_direction != sf::Vector2f(0.f, 0.f)) {
        set_animation(Animation::WALK);
    }

    if (m_current_animation == Animation::WALK && move_direction == sf::Vector2f(0.f, 0.f)) {
        set_animation(Animation::IDLE);
    }

    const auto current_scale = m_sprite.getScale();
    if (move_direction.x < 0 && current_scale.x > 0) {
        m_sprite.setScale(sf::Vector2f(-current_scale.x, current_scale.y));
    } else if (move_direction.x > 0 && current_scale.x < 0) {
        m_sprite.setScale(sf::Vector2f(std::abs(current_scale.x), current_scale.y));
    }

    m_elapsed_time += delta_time;
    if (m_elapsed_time > m_frame_duration) {
        m_current_frame = (m_current_frame + 1) % static_cast<int>(m_animations[m_current_animation].size());
        m_elapsed_time = 0.0f;
        m_sprite.setTextureRect(m_animations[m_current_animation].at(m_current_frame));
    }

    m_sprite.setPosition(m_sprite.getPosition() + move_direction);
}

sf::FloatRect Player::get_bounds() const {
    const auto bounds = m_sprite.getGlobalBounds();
    sf::RectangleShape hit_box(sf::Vector2f(bounds.size.x - 120, bounds.size.y - 30));
    hit_box.setPosition(sf::Vector2f(bounds.position.x + 60, bounds.position.y + 15));
    return hit_box.getGlobalBounds();
}