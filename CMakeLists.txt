cmake_minimum_required(VERSION 3.16)
project(CoinCollector LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3.0 COMPONENTS Window Graphics Audio REQUIRED)

add_executable(coin_collector main.cpp game_objects/coin/coin.cpp game_objects/player/player.cpp
        utilities/game_manager/game_manager.cpp
        utilities/game_manager/game_manager.hpp
        utilities/audio_manager/audio_manager.cpp
        utilities/audio_manager/audio_manager.hpp
        utilities/hud/hud.cpp
        utilities/hud/hud.hpp)
target_link_libraries(coin_collector PRIVATE SFML::Graphics SFML::Window SFML::Audio)

add_custom_command(
    TARGET coin_collector POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/assets
            $<TARGET_FILE_DIR:coin_collector>/assets
)
