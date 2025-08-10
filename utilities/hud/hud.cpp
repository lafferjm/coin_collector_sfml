#include "hud.hpp"
#include <string>

HUD::HUD() : m_font("../assets/fonts/press_start.ttf"), m_score_text(m_font) {
    m_score_text.setString("Score:0");
    m_score_text.setCharacterSize(45);
    m_score_text.setPosition(sf::Vector2f(15.f, 10.f));
    m_score_text.setFillColor(sf::Color(0xee, 0x00, 0xef));
}

void HUD::set_score(int score) {
    m_score_text.setString("Score:" + std::to_string(score));
}

void HUD::draw(sf::RenderWindow &target) const {
    target.draw(m_score_text);
}