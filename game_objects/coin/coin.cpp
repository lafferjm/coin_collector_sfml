#include "coin.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>

Coin::Coin(float scale, const std::string &texture_path, int frame_count)
    : m_sprite(m_texture), m_current_frame(0),
      m_frame_count(frame_count), m_frame_duration(1 / m_animation_fps), m_elapsed_time(0) {
    m_texture = sf::Texture(texture_path, false);
    m_sprite = sf::Sprite(m_texture);
    m_sprite.setTextureRect(sf::IntRect({m_current_frame, 0}, {32, 32}));
    m_sprite.setScale({scale, scale});
}

void Coin::draw(sf::RenderWindow &target) const {
    target.draw(m_sprite);
}

void Coin::update(const float delta_time) {
    m_elapsed_time += delta_time;
    if (m_elapsed_time > m_frame_duration) {
        m_current_frame = (m_current_frame + 1) % m_frame_count;
        m_elapsed_time = 0.0f;
        m_sprite.setTextureRect(sf::IntRect({m_current_frame * 32, 0}, {32, 32}));
    }
}

void Coin::set_position(float x, float y) {
    m_sprite.setPosition(sf::Vector2f({x, y}));
}

sf::FloatRect Coin::get_bounds() const {
    auto const bounds = m_sprite.getGlobalBounds();
    sf::RectangleShape hit_box(sf::Vector2f(bounds.size.x / 2 - 5, bounds.size.y / 2 - 5));
    hit_box.setPosition(sf::Vector2f(bounds.position.x + 20, bounds.position.y + 18));
    return hit_box.getGlobalBounds();
}