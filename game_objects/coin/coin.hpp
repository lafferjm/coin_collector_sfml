#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class Coin {
public:
  Coin(float, const std::string &, int);
  void draw(sf::RenderWindow &) const;
  void update(float);
  void set_position(float, float);
  sf::FloatRect get_bounds() const;

private:
  sf::Sprite m_sprite;
  sf::Texture m_texture;
  int m_current_frame;
  int m_frame_count;
  float m_frame_duration;
  float m_elapsed_time;

  static constexpr float m_animation_fps = 13.f;
};
