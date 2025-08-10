#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

class HUD {
public:
    HUD();
    void set_score(int);
    void draw(sf::RenderWindow &) const;
private:
    sf::Font m_font;
    sf::Text m_score_text;
};
