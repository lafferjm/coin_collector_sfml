cmake_minimum_required(VERSION 3.16)
project(CoinCollector LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3.0 COMPONENTS Window Graphics REQUIRED)

add_executable(coin_collector main.cpp game_objects/coin/coin.cpp game_objects/player/player.cpp)
target_link_libraries(coin_collector PRIVATE SFML::Graphics SFML::Window)

add_custom_command(
    TARGET coin_collector POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/assets
            $<TARGET_FILE_DIR:coin_collector>/assets
)
