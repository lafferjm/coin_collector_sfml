#include <string>

#include <SFML/Graphics.hpp>

#ifndef __COIN_HPP__
#define __COIN_HPP__

class Coin {
public:
  Coin(float, const std::string &, int);
  void draw(sf::RenderWindow &);
  void update(float);
  void set_position(float, float);

private:
  sf::Sprite m_sprite;
  sf::Texture m_texture;
  int m_current_frame;
  int m_frame_count;
  float m_frame_duration;
  float m_elapsed_time;
};

#endif