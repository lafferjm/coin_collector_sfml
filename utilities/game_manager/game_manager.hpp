#pragma once

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <random>

#include "../audio_manager/audio_manager.hpp"
#include "../hud/hud.hpp"
#include "../sprite_group/sprite_group.hpp"
#include "../../game_objects/coin/coin.hpp"
#include "../../game_objects/player/player.hpp"

class GameManager {
public:
    GameManager();

    void run();

private:
    void process_events();

    void update(float);

    void render();

    void handle_collisions();

    void spawn_coins();

    sf::RenderWindow m_window;
    sf::Clock m_clock;

    std::unique_ptr<Player> m_player;
    SpriteGroup<Coin> m_coins;

    int m_score;

    AudioManager m_audio_manager;
    HUD m_hud;

    std::random_device m_rd;
    std::mt19937 m_gen;
    std::uniform_real_distribution<float> m_x_dist;
    std::uniform_real_distribution<float> m_y_dist;

    static constexpr int width = 1024;
    static constexpr int height = 768;
    static constexpr int frame_rate = 60;
    static constexpr float player_speed = 200.f;
    static constexpr int max_coins = 100;
};