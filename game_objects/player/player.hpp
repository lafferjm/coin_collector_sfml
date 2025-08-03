#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class Player {
public:
    Player(float, const std::string &, int);
    void draw(sf::RenderWindow &) const;
private:
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    int m_frame_count;
};