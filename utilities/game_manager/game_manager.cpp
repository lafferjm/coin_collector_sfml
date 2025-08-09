#include "game_manager.hpp"
#include <memory>
#include <random>
#include <iostream>

GameManager::GameManager() : m_window(sf::VideoMode({width, height}), "Coin Collector") {
    m_window.setFramerateLimit(frame_rate);

    m_player = std::make_unique<Player>(5.f, "../assets/sprites/player.png");

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution x_dist(0.f, 1024.f - 32.f);
    std::uniform_real_distribution y_dist(0.f, 768.f - 32.f);

    for (int i = 0; i < 10; i++) {
        const auto coin = std::make_shared<Coin>(2.f, "../assets/sprites/coin.png", 9);
        const float x_position = x_dist(gen);
        const float y_position = y_dist(gen);
        coin->set_position(x_position, y_position);
        m_coins.add(coin);
    }

    m_audio_manager = AudioManager();
}

void GameManager::run() {
    m_audio_manager.play_background_music();

    while (m_window.isOpen()) {
        process_events();
        const float delta_time = m_clock.restart().asSeconds();
        update(delta_time);
        render();

        handle_collisions();
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
    m_player->draw(m_window);
    m_coins.draw(m_window);
    m_window.display();
}

void GameManager::handle_collisions() {
    auto& coins = m_coins.get_objects();

    for (auto it = coins.begin(); it != coins.end(); ) {
        auto coin_bounds = (*it)->get_bounds();
        if (m_player->get_bounds().findIntersection(coin_bounds).has_value()) {
            it = coins.erase(it);
            m_audio_manager.play_coin_collected();
            std::cout << "You collected a coin" << std::endl;
        } else {
            ++it;
        }
    }
}
