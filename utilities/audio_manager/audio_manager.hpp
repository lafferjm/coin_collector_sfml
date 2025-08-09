#pragma once

#include <SFML/Audio.hpp>

class AudioManager {
public:
    AudioManager();
    void play_background_music();
    void play_coin_collected();
private:
    sf::Music m_background_music;
    sf::SoundBuffer m_coin_buffer;
    sf::Sound m_coin_collected;
};
