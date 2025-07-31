#include <SFML/Graphics.hpp>
#include <vector>

#ifndef __SPRITE_GROUP_HPP__
#define __SPRITE_GROUP_HPP__

template <typename T> class SpriteGroup {
public:
  void add(T);
  void draw(sf::RenderWindow &);
  void update(float);

private:
  std::vector<T> m_objects;
};

template <typename T> void SpriteGroup<T>::add(T obj) {
  m_objects.push_back(obj);
}

template <typename T> void SpriteGroup<T>::draw(sf::RenderWindow &window) {
  for (auto &obj : m_objects) {
    obj->draw(window);
  }
}

template <typename T> void SpriteGroup<T>::update(float dt) {
  for (auto &obj : m_objects) {
    obj->update(dt);
  }
}

#endif