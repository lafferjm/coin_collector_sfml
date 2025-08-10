#include "hud.hpp"
#include <string>

HUD::HUD() : m_font("../assets/fonts/arcade_classic.ttf"), m_score_text(m_font) {
    m_score_text.setString("Score: 0");
    m_score_text.setCharacterSize(24);
    m_score_text.setPosition(sf::Vector2f(25.f, 10.f));
}

void HUD::set_score(int score) {
    m_score_text.setString("Score: " + std::to_string(score));
}

void HUD::draw(sf::RenderWindow &target) const {
    target.draw(m_score_text);
}
