#include "audio_manager.hpp"

AudioManager::AudioManager() : m_background_music("../assets/sounds/background_music.ogg"), m_coin_buffer("../assets/sounds/explosion.wav"), m_coin_collected(m_coin_buffer) {
    m_background_music.setLooping(true);
    m_background_music.setVolume(60.f);

    m_coin_collected.setVolume(20.f);
}

void AudioManager::play_background_music() {
    m_background_music.play();
}

void AudioManager::play_coin_collected() {
    m_coin_collected.play();
}
