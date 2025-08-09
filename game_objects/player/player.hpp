#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>

class Player {
public:
    Player(float, const std::string &);
    void draw(sf::RenderWindow &) const;
    void update(float, sf::Vector2f);
private:
    void load_animations();

    sf::Sprite m_sprite;
    sf::Texture m_texture;
    std::unordered_map<std::string, std::vector<sf::IntRect>> m_animations;
    std::string m_current_animation;

    int m_current_frame;
    float m_frame_duration;
    float m_elapsed_time;

    static constexpr float m_animation_fps = 12.f;
};