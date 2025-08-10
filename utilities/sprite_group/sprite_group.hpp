#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <vector>


template<typename T>
class SpriteGroup {
public:
    void add(const std::shared_ptr<T> &);

    void draw(sf::RenderWindow &);

    void update(float);

    std::vector<std::shared_ptr<T> > &get_objects();

private:
    std::vector<std::shared_ptr<T> > m_objects;
};

template<typename T>
void SpriteGroup<T>::add(const std::shared_ptr<T> &obj) {
    m_objects.push_back(obj);
}

template<typename T>
void SpriteGroup<T>::draw(sf::RenderWindow &window) {
    for (auto &obj: m_objects) {
        obj->draw(window);
    }
}

template<typename T>
void SpriteGroup<T>::update(float dt) {
    for (auto &obj: m_objects) {
        obj->update(dt);
    }
}

template<typename T>
std::vector<std::shared_ptr<T> > &SpriteGroup<T>::get_objects() {
    return m_objects;
}