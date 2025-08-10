#include "game_manager.hpp"
#include <memory>
#include <random>
#include <iostream>

GameManager::GameManager() :
    m_window(sf::VideoMode({width, height}), "Coin Collector"),
    m_score(0), m_gen(m_rd()), m_x_dist(0.f, 1024.f - 32.f), m_y_dist(0.f, 768.f - 32.f) {
    m_window.setFramerateLimit(frame_rate);

    m_player = std::make_unique<Player>(5.f, "../assets/sprites/player.png");

    for (int i = 0; i < max_coins; i++) {
        const auto coin = std::make_shared<Coin>(2.f, "../assets/sprites/coin.png", 9);
        const float x_position = m_x_dist(m_gen);
        const float y_position = m_y_dist(m_gen);
        coin->set_position(x_position, y_position);
        m_coins.add(coin);
    }
}

void GameManager::run() {
    m_audio_manager.play_background_music();

    while (m_window.isOpen()) {
        const float delta_time = m_clock.restart().asSeconds();

        process_events();
        update(delta_time);
        render();

        handle_collisions();

        spawn_coins();
    }
}

void GameManager::process_events() {
    while (const auto event = m_window.pollEvent()) {
        if (event->is<sf::Event::Closed>())
            m_window.close();
    }
}

void GameManager::update(const float delta_time) {
    sf::Vector2f move_direction(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) move_direction.x -= 1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) move_direction.x += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) move_direction.y -= 1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) move_direction.y += 1;

    if (move_direction != sf::Vector2f(0.f, 0.f))
        move_direction = move_direction.normalized() * player_speed * delta_time;

    m_player->update(delta_time, move_direction);
    m_coins.update(delta_time);
}

void GameManager::render() {
    m_window.clear(sf::Color::Green);

    m_coins.draw(m_window);
    m_player->draw(m_window);

    m_hud.draw(m_window);

    m_window.display();
}

void GameManager::handle_collisions() {
    auto& coins = m_coins.get_objects();

    for (auto it = coins.begin(); it != coins.end(); ) {
        auto coin_bounds = (*it)->get_bounds();
        if (m_player->get_bounds().findIntersection(coin_bounds).has_value()) {
            it = coins.erase(it);
            m_audio_manager.play_coin_collected();
            m_score += 1;
            m_hud.set_score(m_score);
        } else {
            ++it;
        }
    }
}

void GameManager::spawn_coins() {
    int coin_spawn_count = max_coins - m_coins.get_objects().size();

    for (int i = 0; i < coin_spawn_count; i++) {
        const auto coin = std::make_shared<Coin>(2.f, "../assets/sprites/coin.png", 9);
        const float x_position = m_x_dist(m_gen);
        const float y_position = m_y_dist(m_gen);
        coin->set_position(x_position, y_position);
        m_coins.add(coin);
    }
}