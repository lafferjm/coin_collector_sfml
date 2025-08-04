#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>

class Player {
public:
    Player(float, const std::string &);
    void draw(sf::RenderWindow &) const;
private:
    void load_animations();

    sf::Sprite m_sprite;
    sf::Texture m_texture;
    std::unordered_map<std::string, std::vector<sf::IntRect>> m_animations;
    std::string m_current_animation;
};