cmake_minimum_required(VERSION 3.16)
project(CoinCollector LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SFML 3 with correct component names
find_package(SFML 3.0 COMPONENTS System Window Graphics REQUIRED)

# Add executable
add_executable(coin_collector main.cpp)

# Link SFML libraries using imported targets
target_link_libraries(coin_collector PRIVATE SFML::System SFML::Window SFML::Graphics)