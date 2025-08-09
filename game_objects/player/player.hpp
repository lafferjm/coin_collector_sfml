#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>

class Player {
public:
    enum class Animation {
        IDLE,
        WALK,
    };

    Player(float, const std::string &);
    void draw(sf::RenderWindow &) const;
    void update(float, sf::Vector2f);
private:
    void load_animations();
    void set_animation(Animation);

    sf::Sprite m_sprite;
    sf::Texture m_texture;
    std::unordered_map<Animation, std::vector<sf::IntRect>> m_animations;
    Animation m_current_animation;

    int m_current_frame;
    float m_frame_duration;
    float m_elapsed_time;

    static constexpr float m_animation_fps = 12.f;
};